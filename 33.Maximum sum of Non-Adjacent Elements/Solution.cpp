#include <bits/stdc++.h> 

int dpHelp(vector<int> nums, int index, vector<int>& dp)
{

    if(index>=nums.size())
    {
        return 0;
    }
    if(dp[index]!=-1)
    {
        return dp[index];
    }

    int pickSum = nums[index] + dpHelp(nums, index+2,dp);
    int NotPickSum = dpHelp(nums,index+1,dp);

    int fi = max(pickSum,NotPickSum);
    
    return dp[index] = fi;
}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    int n = nums.size();
    vector<int>dp(n,-1);

    return dpHelp(nums, 0, dp);
}