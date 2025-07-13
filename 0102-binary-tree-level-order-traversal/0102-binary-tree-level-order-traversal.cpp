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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if (root == nullptr) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size() > 0) {
            int level = q.size();
            
            // store the current level of tree
            vector<int> res;
            
            for (int i = 0; i < level; i++) {
                TreeNode* temp = q.front();
                q.pop();
                res.push_back(temp->val);
                
                if (temp->left != nullptr) q.push(temp->left);
                if (temp->right != nullptr) q.push(temp->right);
            }
            
            ans.push_back(res);
        }
        return ans;
    }
};