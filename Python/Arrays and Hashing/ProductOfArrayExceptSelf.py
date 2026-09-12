class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        length = len(nums)
        seen = [1] * length

        left = 1
        right = 1

        for i, num in enumerate(nums):
            seen[i] *= left
            left *= num 

        for i in range(length - 1, -1, -1): #range(start, stop, step)
            #Stop at -1 because we want to include 0 index in the range
            seen[i] *= right
            right *= nums[i]
        return seen 