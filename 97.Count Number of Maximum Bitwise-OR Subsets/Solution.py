class Solution:


    def countMaxOrSubsets(self, nums: List[int]) -> int:
        mxValue=0

        ## Since doing Bitwise Or never reduces we perform a Bitwise or on the entire array to get the maximum possible value
        for num in nums:
            mxValue|= num


        ## Subsequence simple Recursion to iterate through every possible combination
        def backTrack(index,currMx):
            if index == len(nums):
                return 1 if currMx == mxValue else 0
            
            if currMx == mxValue:
                return 1<<(len(nums)-index)
            return backTrack(index + 1, currMx | nums[index]) + \
                   backTrack(index + 1, currMx)
        
        return backTrack(0,0)