/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * }; 
 */
class Solution {
public:
    int maxDia = 0; // Global variable
    int helper(TreeNode* root) {
        if(root == NULL) return 0;
        int dia = level(root->left) + level(root->right);
        maxDia = max(dia, maxDia);
        helper(root->left);
        helper(root->right);
        return maxDia;
    }
    int level(TreeNode* root) {
        if(root == NULL) return 0;
        int levelL = level(root->left);
        int levelR = level(root->right); 
        return 1 + max(levelL, levelR);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDia = 0; 
        return helper(root);
    }
};