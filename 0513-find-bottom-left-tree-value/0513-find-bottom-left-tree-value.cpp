class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

        if(root==NULL) return -1; 

        int left=0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();

            for(int i=0;i<levelSize;i++){
                
                TreeNode* currNode = q.front();
                q.pop();

                if(i==0)  left = currNode->val;
                // means we are pushing the right node first followed by the left node 

                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
        }

        return left; 
   }
};