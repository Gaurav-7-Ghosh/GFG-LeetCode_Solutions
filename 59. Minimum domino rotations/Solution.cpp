class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            
          int res = INT_MAX;
          // Here are trying to check if any of the possible dominoes values can be stacked in either the top row or bottom row
            for (int val = 1; val <= 6; ++val) {
                int top_swaps = 0, bottom_swaps = 0;
                // This is to check whether for the given domino value is it still possible to have all values this either in the top row or bottom
                bool valid = true; 
                for (int i = 0; i < tops.size(); ++i) {
                    if (tops[i] != val && bottoms[i] != val) {
                        valid = false; // Neither top or bottom match so this number cannot be all in top or bottom so moving to the next possible domino 
                        break;
                    }
                    if (tops[i] != val) top_swaps++; // If either top or bottom is the same then we swap and increment the count 
                    if (bottoms[i] != val) bottom_swaps++;
                }
                if (valid)
                    res = min(res, min(top_swaps, bottom_swaps)); // Taking the minimum possible swaps to achieve 
            }
            return res == INT_MAX ? -1 : res;
        }
    };