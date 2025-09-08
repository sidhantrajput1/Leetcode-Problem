class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        int firstPos = k;
        int secondPos = length - k + 1;

        ListNode* node1 = head;
        ListNode* node2 = head;

        for (int i = 1; i < firstPos; i++) {
            node1 = node1->next;
        }

        for (int i = 1; i < secondPos; i++) {
            node2 = node2->next;
        }

        swap(node1->val, node2->val);

        return head;
    }
};