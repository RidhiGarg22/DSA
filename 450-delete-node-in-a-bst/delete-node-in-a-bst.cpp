class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // Node to delete found

            // Case 1: no left child
            if (!root->left) {
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            }
            // Case 2: no right child
            if (!root->right) {
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            }

            // Case 3: two children
            TreeNode* successor = findMin(root->right);
            root->val = successor->val;
            root->right = deleteNode(root->right, successor->val);
        }
        return root;
    }

private:
    TreeNode* findMin(TreeNode* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }
};
