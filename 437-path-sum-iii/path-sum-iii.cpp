
class Solution {
public:
    unordered_map<long long, int> prefix;
    int count = 0;
    int target;

    void dfs(TreeNode* node, long long currSum) {
        if (!node) return;

        currSum += node->val;

        if (prefix.count(currSum - target)) {
            count += prefix[currSum - target];
        }

        prefix[currSum]++;
        dfs(node->left, currSum);
        dfs(node->right, currSum);
        prefix[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        prefix[0] = 1;  // base case
        dfs(root, 0);
        return count;
    }
};
