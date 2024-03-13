 int getPairsCount(int arr[], int n, int k) {
        // code here
        unordered_map<int,int>mp;
         int ans=0;
        for(int i=0;i<n;i++){
            int val=k-arr[i];
            if(mp[val]){
                ans=ans+mp[val];
            }
            mp[arr[i]]++;
        }
        return ans;
    }