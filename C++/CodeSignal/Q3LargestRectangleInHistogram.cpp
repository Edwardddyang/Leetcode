class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> seen;
        int answer = 0; 

        if(heights.size() == 0) 
            return 0; 
        if(heights.size() == 1) 
            return heights[0]; 

        for(int i = 0; i <= heights.size(); i++){
            int height = (i == heights.size()) ? 0 : heights[i]; 

            while(!seen.empty() && height < heights[seen.top()]){
                int pop = heights[seen.top()]; 
                seen.pop(); 
                int left = seen.empty() ? -1 : seen.top();
                int width = i - left - 1; 
                answer = max(answer, pop * width);    
            }
            seen.push(i); 
        }

        return answer; 
    }
};