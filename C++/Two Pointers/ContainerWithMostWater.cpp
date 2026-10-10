class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0; 
        int j = height.size() - 1; 
        int answer = 0; 
        while(i < j){
            int minheight = min(height[i], height[j]); 
            int area = (j - i) * minheight; 
            answer = max(area, answer); 

            if(height[i] <= height[j])
                i++;
            else 
                j--; 
        }
        return answer; 
    }
};