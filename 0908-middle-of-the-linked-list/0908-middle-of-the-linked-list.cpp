class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next; // one step
            fast = fast->next->next; // two step
        }
        // return middle node
        return slow; 
    }
};