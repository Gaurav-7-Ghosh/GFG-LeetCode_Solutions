 vector<int> constructLowerArray(vector<int> &arr) {
        vector<int> ans;
        vector<int> temp;
        for(int i=arr.size()-1;i>=0;i--){
            auto lb=lower_bound(temp.begin(),temp.end(),arr[i]);
            int val=lb-temp.begin();
            ans.insert(ans.begin(),val);
            temp.insert(lb,arr[i]);
        }
        return ans;
    }