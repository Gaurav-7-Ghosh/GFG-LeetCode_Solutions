class Solution {
    public:
        int snakesAndLadders(vector<vector<int>>& board) {
            int n = board.size();
            // initializing a array to store the miniumum number of rolls needed to reach
            // row i 
            vector<int> min_rolls(n * n + 1, -1);
            queue<int> q;
            // since we are in the first row so number of rolls needed to get here is 0
            min_rolls[1] = 0;
            q.push(1);
            while (!q.empty()) {
                // pop each element in the queue which is our start posiiton now
                int x = q.front();
                q.pop();
                for (int i = 1; i <= 6 && x + i <= n * n; i++) {
                    // iterating for all 6 possible values of the dice roll
                    int t = x + i, row = (t - 1) / n, col = (t - 1) % n;
                    // Converting the position to the grid 
                    int v = board[n - 1 - row][row % 2 ? n - 1 - col : col];
                    int y = v > 0 ? v : t; // follow ladder / snake if present
                    if (y == n * n)
                        return min_rolls[x] + 1;
                        // min[rolls] acts as the visited array. Only if we havent seen it 
                        //we push it into the queue and update the value 
                    if (min_rolls[y] == -1) {
                        min_rolls[y] = min_rolls[x] + 1;
                        q.push(y);
                    }
                }
            }
            return -1;
        }
    };