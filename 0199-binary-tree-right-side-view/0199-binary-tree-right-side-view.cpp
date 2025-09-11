class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        vector<int> res;
        queue<TreeNode*> qu;
        qu.push(root);

        while (!qu.empty()) {
            int level = qu.size();

            for (int i = 0; i < level; i++) {
                auto curr = qu.front();
                qu.pop();

                if (i == level - 1) res.push_back(curr->val);

                if (curr->left) qu.push(curr->left);
                if (curr->right) qu.push(curr->right);
            }
        }

        return res;
    }
};