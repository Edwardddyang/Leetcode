class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0; 
        int j = s.size() - 1; 

        while(i <= j){
            if(!isalnum(s[i])){
                i++; 
                continue; 
            }
            else if(!isalnum(s[j])){
                j--; 
                continue; 
            }
            if(tolower(s[i]) != tolower(s[j]))
                return false; 
            i++; //REMEMBER TO HAVE THESE ITERATORS FOR WHILE LOOPS
            j--;
        }
        return true; 
    }
};