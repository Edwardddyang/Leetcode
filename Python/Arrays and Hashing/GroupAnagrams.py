class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        seen = {}

        for s in strs:
            temp = "".join(sorted(s)) #In python strings are immutable. 
            #sorted(s) takes string and returns a list of characters in sorted order. e.g., ['a', 'e', 't']
            #"".join(sorted(s)) takes the list of characters and joins them back into a string. e.g., 'aet'

            if temp not in seen:
                seen[temp] = [] #Intialize new list if sorted string is not in the dictionary 
            seen[temp].append(s) #Add string to vector/list of sorted string 
        return list(seen.values()) #seen.values() returns all lists stored in dictionary. #list converts them into a list 
