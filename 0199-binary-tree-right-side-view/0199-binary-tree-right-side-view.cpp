class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int level = q.size();

            for (int i = 0; i < level; i++) {
                auto curr = q.front();
                q.pop();

                if (i == level - 1) res.push_back(curr->val);

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        return res;
    } 
};