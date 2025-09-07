
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow_prev = nullptr;
        

        while (fast != NULL && fast->next != NULL) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);

        
        slow_prev->next = NULL;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        // cout<<slow->val;      

        return root;  
    }
};