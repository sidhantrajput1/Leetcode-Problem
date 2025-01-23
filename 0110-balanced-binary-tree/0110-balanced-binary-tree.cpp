class Solution {
public:
    int level(TreeNode* root) {
        if(root==NULL) return 0;
        int leverL = level(root->left);
        int levelR =  level(root->right);
        return 1 + max(leverL, levelR);
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int left = level(root->left);
        int right =  level(root->right);
        if(abs( right - left ) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);   
    }
};