class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        // using bfs
        queue<TreeNode*> q;
        q.push(root);

        bool past = false; // check if any past node is true or false

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            // if node is find null then mark past equal to true
            if (node == NULL) {
                past = true;
            } else {
                // if any past node is null then return false because tree is a
                // not complete binary tree
                if (past == true) {
                    return false;
                }

                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};