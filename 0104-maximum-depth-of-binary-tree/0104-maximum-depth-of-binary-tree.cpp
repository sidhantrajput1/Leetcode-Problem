class Solution {
    private : 
    int level(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while(!q.empty()) {
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans++;
        }
        return ans;
    }
public:
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        return level(root);
    }
};