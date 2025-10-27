class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if (root == nullptr) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> result;

        while (!q.empty()) {
            int levelSize = q.size();

            vector<int> res;   

            for (int i = 0; i < levelSize; i++) {
                auto topNode = q.front();
                q.pop();

                res.push_back(topNode->val);

                if (topNode->left) q.push(topNode->left);
                if (topNode->right) q.push(topNode->right);
            }

            result.push_back(res);
        }

        return result;
    }
};