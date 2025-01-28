class Solution {
public:

    void inorder(TreeNode* root, vector<int>& ans) {
        if(root==NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return NULL;

        vector<int> ans;
        inorder(root , ans);
        for(int i = 0; i < ans.size(); i++) {
            for(int j=i+1;j<ans.size();j++){
                if(ans[i]+ans[j]==k) return true;
            }
        }

        return false;
    }
};