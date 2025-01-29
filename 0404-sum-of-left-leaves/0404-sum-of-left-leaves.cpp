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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        int leftSum = 0;

        while(!q.empty()) {
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left && !temp->left->left && !temp->left->right) {
                    leftSum += temp->left->val;
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return leftSum;
    }
};