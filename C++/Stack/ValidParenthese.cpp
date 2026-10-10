//Use a stack (Last in, first out), can only touch the top 
//

class Solution {
public:
    bool isValid(string s) {
        stack<char> seen; 

        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){ //Add opening brack to the stack 
                seen.push(c);
                continue;  
            }
            if(seen.empty()) //If there is no corresponding ( { or [ then it is invalid 
                return false; 
            char top = seen.top(); //Get the opening bracket 
            seen.pop(); //Get rid of it from the stack 
            if(c == '}' && top != '{' || c == ')' && top != '(' || c == ']' && top != '[') //Check validity 
                return false;
            
        }
        return seen.empty(); 
    }
};

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