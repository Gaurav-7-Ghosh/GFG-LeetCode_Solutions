class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_possible = -99999999
        sum =0 
        for i in range (0,len(nums)):
            sum=sum + nums[i]
            if sum > max_possible:
                max_possible = sum
            if sum < 0:
                sum = 0

        return max_possible 