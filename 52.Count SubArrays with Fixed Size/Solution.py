class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        min_i,max_i,bad_i = -1,-1,-1 ## Initializing the all the indexes at -1 
        total = 0
        for i in range (len(nums)):
            if nums[i] < minK or nums[i]>maxK:
                bad_i=i
            if nums[i] == minK:
                min_i = i
            if nums[i] == maxK:
                max_i = i
            total+= max(0,(min(max_i,min_i) - bad_i))
        
        return total
