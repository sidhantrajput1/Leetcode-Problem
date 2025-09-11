class Solution {
public:
    void preOrder(TreeNode* root, int level, vector<int>& res) {
        if (root == nullptr) return;

        if (res.size() < level) res.push_back(root->val);

        preOrder(root->right, level + 1, res);
        preOrder(root->left, level + 1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        preOrder(root, 1, ans);

        return ans;
    }
};