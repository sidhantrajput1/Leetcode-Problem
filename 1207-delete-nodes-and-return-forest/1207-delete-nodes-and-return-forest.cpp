class Solution {
public:

    TreeNode* deleteHelfer(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& result) {
        if (root == NULL) return NULL;

        root->left = deleteHelfer(root->left, st, result);
        root->right = deleteHelfer(root->right, st, result);

        if (st.find(root->val) != st.end()) {
            // If children exist, they become new trees in the forest
            if (root->left != nullptr) {
                result.push_back(root->left);
            }
            if (root->right != nullptr) {
                result.push_back(root->right);
            }
            // Return NULL to parent (disconnect this node)
            return NULL;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;

        unordered_set<int> st;

        for(int &num : to_delete) {
            st.insert(num);
        }

        deleteHelfer(root, st, result);


        if (st.find(root->val) == st.end()) {
            result.push_back(root);
        }

        return result;
    }
};