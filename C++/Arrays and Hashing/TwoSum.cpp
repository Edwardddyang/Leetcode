class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; 
        vector<int> answer; 

        for(int i = 0; i < nums.size(); i++){
            int lookup = target - nums[i]; 
            if(seen.count(lookup)){
                answer.push_back(i); 
                answer.push_back(seen[lookup]);
                return answer; 
            }
            seen[nums[i]] = i; 
        }
        return {}; 
    }
};