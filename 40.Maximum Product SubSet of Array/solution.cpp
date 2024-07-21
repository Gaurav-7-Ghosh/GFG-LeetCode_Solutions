long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
            long ans = 1;
        int mx = INT_MIN;
        for(int i=0; i<arr.size(); i++){
            if(arr[i]!=0){
                ans = (ans*arr[i])%1000000007;
            }
            
            if(arr[i]<0 && mx<arr[i]){
                mx = arr[i];
            }
        }
        
        if(ans<0) return ans/mx;
        return ans;
    }