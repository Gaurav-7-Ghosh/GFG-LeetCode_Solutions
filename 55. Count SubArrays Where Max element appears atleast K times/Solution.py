class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        mx_num = -1
        for i in range (len(nums)):
            if nums[i]>mx_num:
                mx_num=nums[i]
        count = 0 
        for i in range (len(nums)):
            if mx_num == nums[i]:
                count+=1
        if count < k:
            return 0 ##EDGE CASE
        result=0
        start=0
        for num in nums:
            if num == mx_num:
                k -= 1
            while k ==0:
                if nums[start] == mx_num:
                    k += 1
                start += 1
                
            result += start

                
        return result