class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;       // one step
            fast = fast->next->next; // two step
        }
        // return middle node
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* after = nullptr;

        while (curr != nullptr) {
            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        // 1. find mid
        ListNode* mid = middleNode(head);

        // 2. reverse the linked list mid to end
        mid = reverseList(mid);

        // 3. find the max element
        int result = 0;
        ListNode* curr = head;
        while (mid != nullptr) {
            result = max(result, curr->val + mid->val);
            curr = curr->next;
            mid = mid->next;
        }

        return result;
    }
};