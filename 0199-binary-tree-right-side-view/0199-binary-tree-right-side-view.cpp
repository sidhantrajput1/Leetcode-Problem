class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<int> res;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                auto temp = q.front();
                q.pop();
                if (i == levelSize - 1) res.push_back(temp->val);

                if (temp->left)  q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }

        return res;
    }
};