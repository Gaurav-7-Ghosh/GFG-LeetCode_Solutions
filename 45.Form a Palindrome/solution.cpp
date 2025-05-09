int countMin(string str){
        int n = str.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1; 
        }
        
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i < n - length + 1; i++) {
                int j = i + length - 1;
                if (str[i] == str[j]) {
                    if (length == 2) {
                        dp[i][j] = 2; 
                    } else {
                        dp[i][j] = dp[i+1][j-1] + 2; 
                    }
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]); 
                }
            }
        }
        
        int lps_length = dp[0][n-1];
        return n - lps_length;
    }