class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            vector<int> diff(nums.size() + 1, 0);
            // Essentially we are using prefix sum 
            // For each range of query index we are adding 1 to start of query or at index l of the difference
            // array and -1 to the end of the query r.
            /
            for (const auto& q : queries) {
                diff[q[0]]++; // diff[l]++
                if (q[1] + 1 < nums.size())
                    diff[q[1] + 1]--; // diff[r + 1]--
            }

            // Now when we iterate through the array at each index we add the sum of the diff array to know the number of possible operations 
            // than can be performed on this index. If it is more or equal to the value at nums[i] then it can be converted to 0 otherwise not
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++) {
                cnt += diff[i];
                if (nums[i] > cnt)
                    return false;
            }
            return true;
        }
    };