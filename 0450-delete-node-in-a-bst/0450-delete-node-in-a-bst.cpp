class Solution {
public:
    TreeNode* inOrderPredcessor(TreeNode* root) {
        // if(root==NULL || root->left==NULL) return -1; 
        TreeNode* pred = root->left;
        while(pred->right != NULL) pred = pred->right;
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        // leaf nodes
        if(root->val==key) {
            // case 1 : No child
            if(root->left==NULL && root->right==NULL) return NULL;

            // case 2 : 1 Child
            if(root->left == NULL || root->right==NULL) {
                if(root->left!=NULL) return root->left;
                else return root->right;
            }

            // case 3 : 2 child 
            if(root->left != NULL && root->right != NULL) {
                // replace the root with its inorder pred/suc
                // after replacing delete the pred/suc
                TreeNode* pred = inOrderPredcessor(root);
                root->val = pred->val;
                root->left = deleteNode(root->left, pred->val);
            }
        }

        else if(root->val > key) { // go left
            root->left = deleteNode(root->left, key);
        } else { // root-> val < key : go right
            root->right = deleteNode(root->right, key);
        }
    
        return root;
    }
};