
class Solution {
public:
    int length(ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        while(temp != nullptr) {
            temp = temp->next;
            size++;
        }
        return size;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = length(head);

        if (n==len) {
            head = head->next;
            return head;
        }

        for (int i = 1; i < len - n; i++) {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        return head;
    }
};