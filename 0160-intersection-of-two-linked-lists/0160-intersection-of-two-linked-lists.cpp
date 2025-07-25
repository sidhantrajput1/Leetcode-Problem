class Solution {
public:
    int length(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        return size;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = length(headA);
        int len2 = length(headB);

        ListNode* tempA = headA;
        ListNode* tempB = headB;

        if (len1 > len2) {
            int diff = len1 - len2;
            for (int i = 1; i <= diff; i++) {
                tempA = tempA->next;
            }
        } else {
            int diff = len2 - len1;
            for (int i = 1; i <= diff; i++) {
                tempB = tempB->next;
            }
        }

        while (tempA != nullptr && tempB != nullptr) {
            if (tempA == tempB) {
                return tempB;
            }

            tempA = tempA->next;
            tempB = tempB->next;
        }

        return nullptr;
    }
};