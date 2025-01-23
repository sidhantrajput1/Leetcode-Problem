class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return NULL;
        if(root->val==val) return root;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if(temp->val==val)
                return temp;

            if (temp->val > val && temp->left != NULL) 
                q.push(temp->left);
            
            if(temp->val < val && temp->right != NULL) 
                q.push(temp->right);
            
        }
        return NULL;
    }
};