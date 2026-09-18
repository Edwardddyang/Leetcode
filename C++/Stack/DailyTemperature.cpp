class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0); 
        stack<int> seen; 

        for(int i = 0; i < temperatures.size(); i++){
            while(seen.size() > 0 && temperatures[i] > temperatures[seen.top()]){
                answer[seen.top()] = i - seen.top(); 
                seen.pop(); 
            }
            seen.push(i);       
        }
        return answer;  
    }
};