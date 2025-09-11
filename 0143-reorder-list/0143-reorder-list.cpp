class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;

        ListNode* curr = head;

        while (curr != nullptr) {
            st.push(curr);
            curr = curr->next;
        }

        int k = st.size() / 2;
        curr = head;

        while (k--) {
            ListNode* topNode = st.top();
            st.pop();

            ListNode* temp = curr->next;
            curr->next = topNode;
            topNode->next = temp;

            curr = temp; 
        }
        
        curr->next = nullptr;
    }
};