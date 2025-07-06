class Solution {
    public:
        int countDistinct(vector<int>& nums, int k, int p) {
            set<vector<int>>ans;
            int n = nums.size();
            int i,j;
            for(i=0;i<n;i++) // Iterating through every possible start point
            {
                vector<int>tt;
                int ct=0; // count of numbers which are divisible by p 
                for(j=i;j<n;j++)
                {
                    tt.push_back(nums[j]); // Storing each sub-array in answer as long as ct is <=k
                    if(nums[j]%p==0)
                        ++ct;
                    if(ct>k)
                        break;
                    ans.insert(tt);
                        
                }
            }
            return ans.size();
        }
            
        
    };