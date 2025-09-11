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

    
    bool isPalindrome(ListNode* head) {
        // 1. Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half
        ListNode* revNode = reverseList(slow);

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