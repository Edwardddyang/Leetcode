//Go through the entire array and keep track of the index of the heights in a stack 
/*If the current height is smaller than the top of the stack, 
then pop the top of the stack and calculate the area. 
Keep popping until the stack is empty or the top of the stack has a height smaller/equal to the current height.

*/ 
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> seen;
        int answer = 0;
        
        for(int i = 0; i <= heights.size(); i++){
            int height = (i == heights.size()) ? 0 : heights[i]; //If gotten to the end of array, then set height to 0 so that we can pop all the remaining heights in the stack

            while(!seen.empty() && height < heights[seen.top()]){ //If current height smaller than top of stack (last element added), then pop the top of the stack and calculate area
                int pop = heights[seen.top()]; 
                seen.pop(); 
                int left = seen.empty() ? -1 : seen.top(); //Left index 
                int width = i - left - 1; 
                answer = max(answer, pop * width);    
            }
            seen.push(i); 
        }

        return answer; 
    }
};


