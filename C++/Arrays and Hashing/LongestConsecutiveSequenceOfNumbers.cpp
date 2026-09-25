//Create a hashset that stores all numbers in the array. Then loop through it and find the longest consecutive sequence 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) //Empty vector 
            return 0; 
        unordered_set<int> seen; 
        
        //Stores all elements in hashset 
        for(int i = 0; i < nums.size(); i++){
            seen.insert(nums[i]); 
        }

        int answer = 1; //For no consecutive sequence 

        for(const auto& i : seen){
            if(seen.count(i - 1)) //Means not smallest value in consecutive sequence 
                continue; 
            
            int sequence = 1; //Include itself, current # 
            int temp = i; 
        
            while(seen.count(temp + 1)){//Keep counting up 
                sequence++; 
                temp++; 
                answer = max(answer, sequence); 
            }
        }
        return answer; 
    }
};