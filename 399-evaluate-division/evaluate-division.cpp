class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;

    double dfs(const string& cur, const string& target,
               unordered_set<string>& visited) {
        if (cur == target) return 1.0;
        visited.insert(cur);

        for (auto& [next, weight] : graph[cur]) {
            if (!visited.count(next)) {
                double res = dfs(next, target, visited);
                if (res != -1.0)
                    return res * weight;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        graph.clear();

        for (int i = 0; i < equations.size(); i++) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> ans;
        for (auto& q : queries) {
            const string& c = q[0];
            const string& d = q[1];

            if (!graph.count(c) || !graph.count(d)) {
                ans.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                ans.push_back(dfs(c, d, visited));
            }
        }
        return ans;
    }
};
