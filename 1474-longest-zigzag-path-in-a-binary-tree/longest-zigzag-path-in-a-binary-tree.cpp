class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* node, bool goLeft, int len) {
        if (!node) return;
        ans = max(ans, len);

        if (goLeft) {
            dfs(node->left, false, len + 1);  
            dfs(node->right, true, 1);        
        } else {
            dfs(node->right, true, len + 1);  
            dfs(node->left, false, 1);        
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        dfs(root->left, false, 1);   
        dfs(root->right, true, 1);   
        return ans;
    }
};
