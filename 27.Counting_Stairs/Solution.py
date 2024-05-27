class Solution:

    def dphelp(self,n,dp):
        if n == 1:
            return 1
        elif n == 0:
            return 1
        if dp[n] != -1:
            return dp[n]
        else :
            left = self.dphelp(n-1,dp)
            right = self.dphelp(n-2,dp)
            dp[n]=left+right
            return dp[n]
    def climbStairs(self, n: int) -> int:
        dp = [-1] * (n+1)
        return self.dphelp(n,dp)
