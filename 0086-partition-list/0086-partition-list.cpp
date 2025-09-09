class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);

        ListNode* smallP = small;
        ListNode* largeP = large;

        ListNode* curr = head;

        while (curr != nullptr) {
            if (curr->val < x) {
                smallP->next = curr;
                smallP = smallP->next;
            } else {
                largeP->next = curr;
                largeP = largeP->next;
            }
            curr = curr->next;
        }

        // terminate large list
        largeP->next = nullptr;

        // connect small list with large list
        smallP->next = large->next;

        // head is small->next (skip dummy)
        return small->next;
    }
};
