/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
        if(root==NULL) return {}; 

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