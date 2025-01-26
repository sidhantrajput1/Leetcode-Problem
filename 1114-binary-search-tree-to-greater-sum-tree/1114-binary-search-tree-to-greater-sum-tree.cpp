
class Solution {
public:
    void revInorder(TreeNode* root, int& accSum) {
        if(root==NULL) return;
        revInorder(root->right, accSum);
        accSum += root->val;
        root->val = accSum;
        revInorder(root->left, accSum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int accSum = 0;
        revInorder(root, accSum);
        return root;
    }
};