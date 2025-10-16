class Solution {
    public:
        int findSmallestInteger(vector<int>& nums, int v) {
            //Inorder to maximize the mex we divide the numbers by v and then we get a range of remainders from 0 to v-1
            long long n = nums.size(), x, res = 0;
            vector<int> rem(v, 0);
            for (int i = 0; i < n; i++) {
                x = ((nums[i] % v) + v) % v;
                //Store the remainder with count
                rem[x]++;
            }
    
            // Now from 0 we keep checking the remainder array, as long as the number is present we keep increasing and on the
            // first search where the number is not present we return that as the maximum non-negative number found
            while (rem[res % v]--) res++;
            return res;
        }
    };