class Solution {
    public:
        int candy(vector<int>& ratings, int cnt = 0) {
            int n = ratings.size();
            vector<int> candies(n, 1);
    
            for (int i = 1; i < n; i++) 
                if (ratings[i] > ratings[i - 1])
                    candies[i] = candies[i - 1] + 1;
            
            for (int i = n - 1; i > 0; i--) {
                if (ratings[i - 1] > ratings[i])
                    candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
                cnt += candies[i - 1];
            }
            return cnt + candies[n - 1];
        }
    };



//     The problem requires each child to get at least one candy, and children with a higher rating than their immediate neighbors must get more candies than them.
// A greedy approach in two passes (left to right and right to left) ensures that all the conditions are satisfied optimally.

// Approach

// Initialize an array cand of size n with all elements as 1, since each child must get at least one candy.
// First Pass (Left to Right):
// If a child has a higher rating than the previous one, give them cand[i - 1] + 1 candies.
// Second Pass (Right to Left):
// If a child has a higher rating than the next one and currently has less than or equal candies, update their candies to cand[i + 1] + 1.
// Sum up all values in the cand array to get the minimum number of candies required.