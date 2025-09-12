class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool solve(TreeNode* root, int idx, int totalNodes) {
        if (root == NULL) return true;

        if (idx > totalNodes) return false;

        return solve(root->left, 2 * idx, totalNodes) &&
               solve(root->right, 2 * idx + 1, totalNodes);
    }

    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);
        return solve(root, 1, totalNodes);
    }
};