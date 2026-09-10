class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False 

        seen = [0] * 26 
        
        for c in s:
            seen[ord(c) - ord('a')] += 1
        for c in t: 
            seen[ord(c) - ord('a')] -= 1
        
        for i in seen: 
            if i != 0: 
                return False; 
        return True; 