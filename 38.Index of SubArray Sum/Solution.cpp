vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        vector<int> indexes;
        int start = 0, end =0;
        int sum =0;
        int e =0; // Keeping track of the number of elements currently in the subarray
        
        for(int i =0;i<n;i++)
        {
            sum+=arr[i];
            e++;
            while(sum>s)
            {
                sum-=arr[start];
                e--;
                start++;
            }
            
            if(sum==s && e!=0)
            {
              indexes.push_back(start+1);
              indexes.push_back(i+1);
              return indexes;
            }
            
        }
        
        indexes.push_back(-1);
        return indexes;
    }