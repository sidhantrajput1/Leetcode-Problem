class Solution {
public:
    ListNode* mergeTwoSortedList(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoSortedList(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoSortedList(list1, list2->next);
            return list2;
        }

        return nullptr;
    }

    ListNode* partitionAndMergeList(vector<ListNode*>& lists, int start, int end) {
        if (start > end) return nullptr;

        if (start == end) {
            return lists[start];
        }

        int mid = start + (end - start) / 2;

        ListNode* l1 = partitionAndMergeList(lists, start, mid); 
        ListNode* l2 = partitionAndMergeList(lists, mid + 1, end); 


        return mergeTwoSortedList(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();

        return partitionAndMergeList(lists, 0, k - 1);
    }
};