class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0); //Initialize vector of temperatures.size() with 0s or else you cant do answer[index] = value 
        stack<int> seen; 

        //Track the indexes of the temperatures, not the actual values because you need to find the difference between the indexes to get the # of days until a warmer temperature
        for(int i = 0; i < temperatures.size(); i++){
            while(seen.size() > 0 && temperatures[i] > temperatures[seen.top()]){ //Make sure seen.size() > 0 or else runtime error from trying to access empty stack 
                answer[seen.top()] = i - seen.top(); //# of days passed = current day - index of other previous day 
                seen.pop(); 
            }
            seen.push(i);       
        }
        return answer;  
    }
};