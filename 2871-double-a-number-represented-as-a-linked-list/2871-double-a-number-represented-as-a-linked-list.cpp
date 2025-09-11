class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<ListNode*> st;
        
        ListNode* curr = head;

        while (curr != nullptr) {
            st.push(curr);
            curr = curr->next;
        }

        int carry = 0;

        while (!st.empty()) {
            auto node = st.top();
            st.pop();

            int val = node->val * 2 + carry;
            node->val = val % 10;
            carry = val / 10;
        }

        if (carry > 0) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }

        return head;

    }
};