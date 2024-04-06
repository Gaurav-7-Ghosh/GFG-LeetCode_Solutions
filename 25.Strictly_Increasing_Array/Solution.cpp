int min_operations(vector<int>& nums) {
        // Code here
        int n = nums.size();
    vector<int> dp(n,1);
    int LIS=1;
    // i running on the outer perimeter
    for(int i=1;i<n;i++)
    {
        // j running from 0 to i checking whether if 
        for(int j=0;j<i;j++)
        {   
            // The second condition is because if the array has to be strictly increasing 
            // and for this we are not changing the value of i and j for which the length 
            // is to be caluclated, the difference must be atleast in equal to the difference
            // of the indexes in order to be able to fill the middle  elements without
            // breaking the strictly increasing property.
            
            // Example 2 and 3 cannot have 2 or 3 elements between them as there is 
            // no way to find 2 or 3 integers which can maintain the strictly increasing 
            // property.
            if(nums[i]>nums[j] && (nums[i]-nums[j])>=(i-j))
            {
                //
                dp[i] = max(1+dp[j],dp[i]);
                LIS = max(LIS,dp[i]);
            }
        }
    }
    return (n-LIS);
    }