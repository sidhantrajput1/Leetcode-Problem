class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);

        int count = 0;
        while(!q.empty()) {
            int levelSize = q.size();
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            
            count++;
        }
        return count;
    }
};