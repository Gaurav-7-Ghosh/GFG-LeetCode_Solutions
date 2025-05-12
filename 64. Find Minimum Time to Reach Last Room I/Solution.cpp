
#include <bits/stdc++.h>

class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int m = moveTime.size();
            int n = moveTime[0].size();
    
            // Directions: up, left, right, down
            vector<int> dx = {-1, 0, 0, 1};
            vector<int> dy = {0, -1, 1, 0};
    
            // Min-heap: stores {currentTime, x, y}
            priority_queue<tuple<int, int, int>,
                           vector<tuple<int, int, int>>,
                           greater<>> pq;
    
            pq.push({0, 0, 0}); // Start from top-left at time 0
    
            // Time to reach each cell; initialized to INF
            vector<vector<int>> minTime(m, vector<int>(n, INT_MAX));
            minTime[0][0] = 0;
    
            while (!pq.empty()) {
                auto [time, x, y] = pq.top(); pq.pop();
    
                if (x == m - 1 && y == n - 1) return time;
    
                if (time > minTime[x][y]) continue; // Already found a better path
    
                for (int dir = 0; dir < 4; ++dir) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
    
                    if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                        int waitTime = (time >= moveTime[nx][ny]) ? time + 1 : moveTime[nx][ny] + 1;
    
                        if (waitTime < minTime[nx][ny]) {
                            minTime[nx][ny] = waitTime;
                            pq.push({waitTime, nx, ny});
                        }
                    }
                }
            }
    
            return -1; // No path found (shouldn't happen in well-formed inputs)
        }
    };
    