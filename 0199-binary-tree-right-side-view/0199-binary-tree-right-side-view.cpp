class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if(root==NULL) return {}; 

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            for(int i=0;i<levelSize;i++){
                
                TreeNode* currNode = q.front();
                q.pop();

                if(i==0)  ans.push_back(currNode->val);  // agar i==0 hai , to iska mtlb ye hai ki particular level ke jo sbse right me hai vhi ele aaega 
                 
                // means we are pushing the right node first followed by the left node 

                if(currNode->right) q.push(currNode->right);
                if(currNode->left) q.push(currNode->left);

            }
        }

        return ans;
    }
};