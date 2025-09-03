class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited; // store visited nodes

        ListNode* current = head;
        while(current) {
            // If the node is already visited, cycle start found
            if (visited.find(current) != visited.end())  return current;

            visited.insert(current);
            current = current->next;
        }

        return nullptr;
    }
};