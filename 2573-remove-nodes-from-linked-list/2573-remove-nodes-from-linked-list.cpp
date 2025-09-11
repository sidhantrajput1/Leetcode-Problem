class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> st;

        ListNode* curr = head;
        while(curr != nullptr) {
            st.push(curr);
            curr = curr->next;
        }

        ListNode* maxNode = st.top();
        st.pop();

        ListNode* newHead = maxNode;
        maxNode->next = nullptr;

        while(!st.empty()) {
            auto topNode = st.top();
            st.pop();

            if (topNode->val >= maxNode->val) {
                // keep this node
                topNode->next = newHead;
                newHead = topNode;
                maxNode = topNode;
            }
        }

        return maxNode;
    }
};