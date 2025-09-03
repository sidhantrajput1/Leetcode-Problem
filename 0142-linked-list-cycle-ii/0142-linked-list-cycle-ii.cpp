class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Edge case: if list is empty or has only one node → no cycle possible
        if (!head || !head->next) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Detect Cycle
        while(fast && fast->next) {
            slow = slow->next; // one step
            fast = fast->next->next; // two step

            // if slow and fast pointer meet then break the loop
            if (slow == fast) break;
        }

        // no cycle detect
        if (slow != fast) return nullptr;

        // find start of cycle
        ListNode* temp = head;
        while (temp != slow) {
            slow = slow->next;
            temp = temp->next;
        }

        return slow; // start of cycle
    }
};