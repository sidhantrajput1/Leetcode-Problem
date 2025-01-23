class Solution {
public:
    int height(TreeNode* root) {
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()) {
            int levelSize = q.size();
            ans++;
            for(int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int left = height(root->left);
        int right = height(root->right);
        if(abs( right - left ) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);   
    }
};