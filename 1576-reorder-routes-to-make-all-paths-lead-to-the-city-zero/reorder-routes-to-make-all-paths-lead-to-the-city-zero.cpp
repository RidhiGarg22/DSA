class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        
        for (auto &e : connections) {
            adj[e[0]].push_back({e[1], 1}); // original direction
            adj[e[1]].push_back({e[0], 0}); // reverse direction
        }
        
        int changes = 0;
        vector<bool> visited(n, false);
        
        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            for (auto &[v, cost] : adj[u]) {
                if (!visited[v]) {
                    changes += cost;
                    dfs(v);
                }
            }
        };
        
        dfs(0);
        return changes;
    }
};
