//Sort all the strings, then compare in hashmap the sorted strings to see if they are anagrams 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer; 

        unordered_map<string, vector<string>> seen; 

        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());  //Sorts the string itself does not make copy 
            seen[temp].push_back(strs[i]); 
        }

        for(const auto& pair : seen){
            answer.push_back(pair.second); 
        }
        return answer; 
    }
};

