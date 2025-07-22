class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        i,j = 0,0
        digit_counts = defaultdict(int)
        curr_sum=0
        mx_sum=0
        for j in range(len(nums)):
            if digit_counts[nums[j]]==0:
                digit_counts[nums[j]]+=1
                curr_sum+=nums[j]
                mx_sum=max(mx_sum,curr_sum)
            else:
                while digit_counts[nums[j]]!=0:
                    digit_counts[nums[i]]-=1
                    curr_sum-=nums[i]
                    i+=1
                digit_counts[nums[j]]=1
                curr_sum+=nums[j]
        
        return mx_sum
            