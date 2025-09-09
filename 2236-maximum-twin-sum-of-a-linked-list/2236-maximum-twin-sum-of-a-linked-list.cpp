class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> list;

        ListNode* curr = head;

        while (curr != nullptr) {
            list.push_back(curr->val);
            curr = curr->next;
        }

        int i = 0, j = list.size() - 1;
        int result = 0;
        while (i < j) {
            result = max(list[i] + list[j], result);
            i++; j--;
        }

        return result;
    }
};