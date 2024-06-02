def dpHelp(index:int, heights:List[int] ,dp):
    if index ==0:
        return 0
    
    if dp[index] !=-1:
        return dp[index]
    left = dpHelp(index-1,heights,dp) + abs(heights[index] - heights[index-1])
    
    right =99999
    if index > 1:
        right = dpHelp(index-2,heights,dp) + abs(heights[index] - heights[index-2])
    

    dp[index] = min(left,right)
    return min (left,right)
        
  
def frogJump(n: int, heights: List[int]) -> int:

    # Write your code here.
    dp = [-1] * (n+1)
    return dpHelp(n-1,heights,dp)