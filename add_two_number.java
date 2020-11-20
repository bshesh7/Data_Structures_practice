// Singly Linked List
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        ListNode p = l1;
        ListNode q = l2;
        int carry = 0;
        while((p != null) || (q != null)){
            int a,b;
            if(p!=null){
                a = p.val;
            }else
            {
                a = 0;
            }
            if(q!=null){
                b = q.val;
            }else{
                b = 0;
            }
            
            int val = a + b + carry;
     
            current.next  = new ListNode(val%10);
            current = current.next;
            
            if(val>=10){
                carry = 1;
            }else{
                carry = 0;
            }
            if(p!=null){
                p = p.next;
            }
            if(q!=null){
                q= q.next;
            }
            
        }
        return dummy.next;      
    }
}