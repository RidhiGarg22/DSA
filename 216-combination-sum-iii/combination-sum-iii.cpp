class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(1, k, n, path, result);
        return result;
    }

    void backtrack(int start, int k, int target,
                   vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == k) {
            if (target == 0)
                result.push_back(path);
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > target) break;   // pruning
            path.push_back(i);
            backtrack(i + 1, k, target - i, path, result);
            path.pop_back();
        }
    }
};
