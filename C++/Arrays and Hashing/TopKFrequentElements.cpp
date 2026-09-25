/*
1. Count frequency of each element using hashmap 
2. Since each integer can only appear at most nums.size() times, make "bucket" array of that size 
3. Each index (vector<int> of bucket array represents how many times the integer appears 
4. Go through each index of bucket array from highest index to lowest for most frequent element 
*/ 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> seen; //Integer, frequency 
        vector<vector<int>> bucket(nums.size() + 1);  //Initialize vector to only hold nums.size() # of integers 
        vector<int> answer; 

        for(int num : nums){
            seen[num]++; //Hashmaps with int initiate with value 0 
        }

        for(const auto& pair : seen){
            bucket[pair.second].push_back(pair.first); 
        }

        for(int i = bucket.size() - 1; i >= 0; i--){
            for(int num : bucket[i]){ //bucket[i] is a vector<int> 
                answer.push_back(num); 
                if(answer.size() == k)
                    return answer; 
            }
        }

        return answer; 
    }
};

