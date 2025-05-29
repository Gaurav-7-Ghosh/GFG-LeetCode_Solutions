class Solution {
    public:
        // Method to build the adjcency List for each Tree
        vector<vector<int>> buildList(const vector<vector<int>>& edges) {
            vector<vector<int>> adj(edges.size() + 1);
            for (auto &e : edges) {
                adj[e[0]].push_back(e[1]);
                adj[e[1]].push_back(e[0]);
            }
            return adj;
        }
        
        // DFS traversal to find the total number of nodes reachable from node u in K steps
        int dfs(const vector<vector<int>>& adj, int u, int p, int k) {
            if (k < 0) return 0;
            int cnt = 1; 
            for (int v : adj[u])
                if (v != p) cnt += dfs(adj, v, u, k-1);
            return cnt;
        }
        
        vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
            auto adj1 = buildList(edges1), adj2 = buildList(edges2);
            int n = adj1.size(), m = adj2.size(), maxiB = 0;
            vector<int> res(n);
    
            // Since one jump will be taken to reach Tree 2 from Tree 1 we check 
            // for which node we get the maximum number of nodes reachable in k-1 steps
            // Then for all possible nodes in tree 1 we will connect to that node only 
            // for maximum target nodes 
            for (int i = 0; i < m; i++) maxiB = max(maxiB, dfs(adj2, i, -1, k - 1));
            //Now for every node in tree 1 we check the maximum number of nodes it can 
            //reach in k steps and then add the max value we got from tree 2
            for (int i = 0; i < n; i++) res[i] = dfs(adj1, i, -1, k) + maxiB;
            return res;
        }
    };