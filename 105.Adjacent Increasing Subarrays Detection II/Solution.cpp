class Solution {
    public:
        int maxIncreasingSubarrays(vector<int>& nums) {
            int n = nums.size();
            //We traverse the array nums once, during which we use cnt and precnt to record the length of the current strictly increasing subarray
            // and the length of the previously increasing subarray
    
    
            int cnt = 1, precnt = 0, ans = 0;
            //count is set to 1 as the first element is itself a strictly increasing array of size 1 and previous_count to 0 
            for (int i = 1; i < n; ++i) {
                if (nums[i] > nums[i - 1]) {
                    //Update the count if the next number is strictly larger
                    ++cnt;
                } else {
                    //shift current value of count to previous_count and reset current count to 1. 
                    precnt = cnt;
                    cnt = 1;
                }
                //With preCount and count representing two arrays we can take the min of them as a possible answer
                ans = max(ans, min(precnt, cnt));
                // Or for the current strictly increasing array we split it into two to take it as max possible
                ans = max(ans, cnt / 2);
            }
            return ans;
        }
    };