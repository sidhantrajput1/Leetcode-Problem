class Solution {
public:
    void inorder(TreeNode* root, unordered_set<int>& s) {
        if(root==NULL) return;
        inorder(root->left, s);
        s.insert(root->val);
        inorder(root->right, s);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        inorder(root, s);
        bool flag = false;
        for(auto ele:s){
            int ans=k-ele;
            if(ele!=ans && s.find(ans)!=s.end()) return true;
        } 
        return flag;
     }
};