class Solution {
    private int maxSum(int[] arr, int k, int[] dp, int start) {
        //We can observe that for each element, we have two options: 
        //1. choose this element in the current subarray or 
        //2. choose to end the current subarray before this element and start another one from this element

        int N = arr.length;

        if (start >= N) {
            return 0;
        }

        // Return the already calculated answer.
        if (dp[start] != -1) {
            return dp[start];
        }
    
        int currMax = 0, ans = 0;
        int end = Math.min(N, start + k);
        for (int i = start; i < end; i++) {
            currMax = Math.max(currMax, arr[i]);
             //The sum of the current subarray will be currMax * length of subarray because each element's value will be changed to currMax. 
            //For the sum of the remaining array, we will make the recursive call to the function with the next index as the starting element of the array.
            ans = Math.max(ans, currMax * (i - start + 1) + maxSum(arr, k, dp, i + 1));
        }

        // Store the answer to be reused.
        return dp[start] = ans;
    }

    public int maxSumAfterPartitioning(int[] arr, int k) {
        int[] dp = new int[arr.length];
        Arrays.fill(dp, -1);

        return maxSum(arr, k, dp, 0);
    }
}