class Solution {
    public:
        const int MOD = 1e9 + 7;
    
        int dfs(int ch, int t, vector<vector<int>>& dp) {
            // If no transformations left return single character
            if (t == 0) return 1;
            if (dp[ch][t] != -1) return dp[ch][t];
    
            if (ch == 25) { // 'z' 
                // If the current character is Z then we have to apply remaining transformations to the two characters 'a' and 'b'

                dp[ch][t] = (dfs(0, t - 1, dp) + dfs(1, t - 1, dp)) % MOD;
            } else {
                dp[ch][t] = dfs(ch + 1, t - 1, dp);
            }
    
            return dp[ch][t];
        }
    
        int lengthAfterTransformations(string s, int t) {
            // Creating a DP array to store the number of characters 
            //possible if applying t transformations to character c[0-25]{since only lowercase character}
            vector<vector<int>> dp(26, vector<int>(t + 1, -1));
            int result = 0;
    
            for (char c : s) {
                result = (result + dfs(c - 'a', t, dp)) % MOD;
            }
    
            return result;
        }
    };
    