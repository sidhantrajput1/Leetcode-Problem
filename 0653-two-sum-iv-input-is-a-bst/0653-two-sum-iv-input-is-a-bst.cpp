class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if(root==NULL) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);
        int st = 0;
        int end = ans.size() - 1;
        while(st<end) {
            int sum = ans[st] + ans[end];
            if(sum==k) return true;
            else if (sum < k ) st++ ;
            else end--;
        }
        return false;
     }
};