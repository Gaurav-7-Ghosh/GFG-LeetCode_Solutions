class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        i,start =0,0 
        sum =0
        count=0 
        for i in range (len(nums)):
            sum=sum+nums[i]
            total = sum * (i-start+1)
            while total >= k:
                sum-=nums[start]
                start+=1
                total=sum *(i-start+1)
            print(i,start)
            count+= (i-start+1)
        return count