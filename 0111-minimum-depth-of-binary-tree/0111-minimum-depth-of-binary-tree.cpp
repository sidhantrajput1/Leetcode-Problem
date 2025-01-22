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
    int level(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()){
            int levelSize = q.size();
            ans++;
            for(int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left==nullptr && temp->right==nullptr) {
                    return ans;
                }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        return level(root);
    }
};