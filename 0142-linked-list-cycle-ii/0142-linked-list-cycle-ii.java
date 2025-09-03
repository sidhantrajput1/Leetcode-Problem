public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null) return null;
        if(head.next == null ) 
          return null;

        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if(fast == slow) break;
        }

        if(fast == null || fast.next == null) return null;

        ListNode temp =head;
        while(temp != slow) {
            slow = slow.next;
            temp = temp.next;
        }
        return slow;
    }
}