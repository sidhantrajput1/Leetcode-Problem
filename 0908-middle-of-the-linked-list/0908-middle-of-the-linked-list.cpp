/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        while(temp != nullptr) {
            temp = temp->next;
            size++;
        }
        return size;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;

        int mid = length(head) / 2;
        
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        return temp;
    }
};