class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(q.size() > 0) {
            int level = q.size();
            vector<int> res;
            for(int i = 0; i < level; i++) {
                TreeNode* temp = q.front();
                q.pop();
                res.push_back(temp->val);
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
            ans.push_back(res);
        }
        return ans;
    }
};