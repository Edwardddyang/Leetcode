class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        seen = set() #seen is a set, only stores single values 
        for num in nums: 
            if num in seen: 
                return True
            seen.add(num) #num already holds the value in nums 
        return False 