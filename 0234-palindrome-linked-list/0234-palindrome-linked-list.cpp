class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return last;
    }

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    bool isPalindrome(ListNode* head) {
        // 1. Find middle
        ListNode* mid = findMiddle(head);

        // 2. Reverse second half
        ListNode* revNode = reverseList(mid);

        // 3. Compare both halves
        ListNode* first = head;
        ListNode* second = revNode;

        while (second != nullptr) {
            if (first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};