//GFG POTD 24-02-2024
// A number n can be broken into three parts n/2, n/3, and n/4 (consider only the integer part). Each number obtained in this process can be divided further recursively. Find the maximum sum that can be obtained by summing up the divided parts together.
// Note: It is possible that we don't divide the number at all.
#include<stdio.h>
#include<bits/stdc++.h>
#include <vector>
#include <valarray>


class Solution
{
    public:
    
        void dphelper(int n,vector<int>& dp)
        {
            if(n==0)
            {
                return ;
            }
            if(dp[n]==-1)
            {
                int b1 = n/2;
                int b2 = n/3;
                int b3 = n/4;
                dp[n]=max(n,b1+b2+b3);
                
                dphelper(b1,dp);
                dphelper(b2,dp);
                dphelper(b3,dp);
                
                if(dp[b1]>b1)
                {
                    dp[n]=dp[n]-b1+dp[b1];
                }
                if(dp[b2]>b2)
                {
                    dp[n]=dp[n]-b2+dp[b2];
                }
                if(dp[b3]>b3)
                {
                    dp[n]=dp[n]-b3+dp[b3];
                }
                
                
                
            }
            
            
        }
        int maxSum(int n)
        {
            //code here.
            if(n==0)
            {
                return 0;
            }
            vector<int> dp(n+1,-1);
            dphelper(n,dp);
            int mxSum=0;
            
            return dp[n];
            
            
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}