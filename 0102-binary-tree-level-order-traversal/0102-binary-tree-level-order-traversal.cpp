class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return  {};

        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> res;
            int level = q.size();

            for (int i = 0; i < level; i++) {
                auto curr = q.front();
                q.pop();

                res.push_back(curr->val);

                if (curr->left) 
                    q.push(curr->left);
                
                if (curr->right) 
                    q.push(curr->right);
                
            }

            ans.push_back(res);
            res.clear();
        }

        return ans;
    }
};