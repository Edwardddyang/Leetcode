class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> seen; 
        vector<vector<string>> answer; 

        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i]; 
            sort(temp.begin(), temp.end());
            seen[temp].push_back(strs[i]); 
        }

        for(const auto& pair : seen){
            answer.push_back(pair.second);
        }

        return answer; 
    }
};