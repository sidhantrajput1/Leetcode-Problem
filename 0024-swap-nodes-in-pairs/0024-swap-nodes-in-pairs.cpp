class Solution {
public:
    ListNode* swapPair(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        /*
            A = head
            B = hed->next
            C = head->next->next
         */
         
        ListNode* temp = head->next;
        head->next = swapPair(head->next->next);
        temp->next = head;

        return temp;
    }
    ListNode* swapPairs(ListNode* head) {
        return swapPair(head);
    }
};