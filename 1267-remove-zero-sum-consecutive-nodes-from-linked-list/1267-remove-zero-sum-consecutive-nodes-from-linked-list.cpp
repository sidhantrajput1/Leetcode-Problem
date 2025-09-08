class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum = 0;
        unordered_map<int, ListNode*> mp;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy;

        while (head != nullptr) {
            prefixSum += head->val;

            if (mp.find(prefixSum) != mp.end()) {
                // Found a zero-sum sequence
                ListNode* start = mp[prefixSum];
                ListNode* temp = start->next;

                int sum = prefixSum;
                // Remove all prefix sums in this range
                while (temp != head) {
                    sum += temp->val;
                    mp.erase(sum);
                    temp = temp->next;
                }

                // Bypass the zero-sum sequence
                start->next = head->next;

            } else {
                mp[prefixSum] = head;
            }

            head = head->next;
        }

        return dummy->next;
    }
};
