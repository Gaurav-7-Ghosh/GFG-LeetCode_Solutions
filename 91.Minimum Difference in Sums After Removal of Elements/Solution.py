import heapq

class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        n = len(nums) // 3
    
        ## Since it always will be leftsum - rightSum we need to maximize right and minimize left 
        # Phase 1: Calculate prefix minimum sums
        prefix_min_sum = [0] * len(nums)
        max_heap = []
        current_sum = 0
        
        for i in range(2 * n):
            current_sum += nums[i]
            heapq.heappush(max_heap, -nums[i])
            
            if len(max_heap) > n:
                largest = -heapq.heappop(max_heap)
                current_sum -= largest
            
            if len(max_heap) == n:
                prefix_min_sum[i] = current_sum
        
        # Phase 2: Calculate suffix maximum sums
        suffix_max_sum = [0] * len(nums)
        min_heap = []
        current_sum = 0
        
        for i in range(len(nums) - 1, n - 1, -1):
            current_sum += nums[i]
            heapq.heappush(min_heap, nums[i])
            
            if len(min_heap) > n:
                smallest = heapq.heappop(min_heap)
                current_sum -= smallest
            
            if len(min_heap) == n:
                suffix_max_sum[i] = current_sum
        
        # Phase 3: Find minimum difference
        ## here since we always delete n numbers at extreme cases we can delete first n, middle n or last n. So here the leftSum can go till max 2n and rightSum can 
        ## start from early as n. 
        min_diff = float('inf')
        for i in range(n-1, 2 * n):
            diff = prefix_min_sum[i] - suffix_max_sum[i + 1]
            min_diff = min(min_diff, diff)
        
        return min_diff
            