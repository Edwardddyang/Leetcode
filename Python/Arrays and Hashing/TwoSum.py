class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        seen = {}

        for i, num in enumerate(nums):
            lookup = target - num 
            if lookup in seen:
                return[i, seen[lookup]]
            seen[num] = i  

        return []       