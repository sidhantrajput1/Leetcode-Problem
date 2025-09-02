class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenStart = even;

        while (even && even->next) {
            odd->next = even->next;   // link odd to next odd
            odd = odd->next;          // move odd forward

            even->next = odd->next;   // link even to next even
            even = even->next;        // move even forward
        }

        odd->next = evenStart;  // attach even list at end of odd list
        return head;
    }
};
