/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        ListNode temp = head;
        ListNode oddHead  = new ListNode(Integer.MAX_VALUE) ;
        ListNode evenHead = new ListNode(Integer.MAX_VALUE);
        ListNode oddtemp = oddHead;
        ListNode eventemp = evenHead;

        if(head == null ) return null;
        if(head.next == null ) return head;

        int count = 0;
        while(temp!=null){
            count ++;
            temp = temp.next;
        }

        temp = head ;

        System.out.println(count);

        for(int i=1 ; i<=count ;i++){

            ListNode newNode = new ListNode(temp.val);
            if( i%2 != 0 ){
                // odd indices
                oddtemp.next = newNode ;
                oddtemp = oddtemp.next;
                temp = temp.next;

            }else{
                // even indicess
                eventemp.next = newNode ;
                eventemp = eventemp.next ;
                temp = temp.next;
            }
        }

        oddHead = oddHead.next;
        evenHead = evenHead.next;
        oddtemp.next = evenHead;

        return oddHead;

    }
}