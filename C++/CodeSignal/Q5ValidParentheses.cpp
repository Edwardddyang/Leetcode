class Solution {
public:
    bool isValid(string s) {
        stack<char> seen; 

        for(int i = 0; i < s.length(); i++){
            if(seen.empty() || s[i] == '{' || s[i] == '(' || s[i] == '[')
                seen.push(s[i]); 
            else if(s[i] == ')' && seen.top() == '(')
                seen.pop(); 
            else if(s[i] == '}' && seen.top() == '{')
                seen.pop();
            else if(s[i] == ']' && seen.top() == '[')
                seen.pop(); 
            else 
                return false; 
        }
        return seen.empty(); 
    }
};