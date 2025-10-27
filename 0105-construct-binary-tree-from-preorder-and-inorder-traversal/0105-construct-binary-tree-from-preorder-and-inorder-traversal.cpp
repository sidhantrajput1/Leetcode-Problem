class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int& idx) {
        if (start > end) return nullptr;

        int rootVal = preorder[idx];   // pick current root
        idx++;                         // move to next root for recursion

        // find root in inorder[]
        int pos = start;
        for (int i = start; i <= end; i++) {
            if (inorder[i] == rootVal) {
                pos = i;
                break;
            }
        }

        TreeNode* root = new TreeNode(rootVal);

        // build left and right subtrees
        root->left  = solve(preorder, inorder, start, pos - 1, idx);
        root->right = solve(preorder, inorder, pos + 1, end, idx);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return solve(preorder, inorder, 0, inorder.size() - 1, idx);
    }   
};
