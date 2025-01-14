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
    // find the level fo tree
    int levels(TreeNode* root) {
        if(root==NULL) return 0;
        return 1 + max(levels(root->left) , levels(root->right));
    }

    void printNthLevelOfElement(TreeNode* root, int curr, int level, vector<int>& v) {
        if(root==NULL) return;
        if(curr == level) {
            v.push_back(root->val);
            return;
        }
        printNthLevelOfElement(root->left, curr+1, level, v);
        printNthLevelOfElement(root->right, curr+1, level, v);
    }

    // bfs traversal
    void leveltraversal(TreeNode* root, vector<vector<int>>& ans) {
        int n = levels(root);
        for(int i = 1; i <= n; i++) {
            vector<int> v;
            printNthLevelOfElement(root, 1, i, v);
            ans.push_back(v);
            cout<<endl;
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        leveltraversal(root, ans);
        return ans;
    }
};