/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        
        ListNode dummy_head = new ListNode(0);
        ListNode l3 = dummy_head;
        int carry = 0;
        // first this loop will continue until we reach the end of both the lists.
        while(l1!=null || l2!=null){
            //check if l1 or l2 null if then assume 0
           int l1_val = (l1!=null) ? l1.val:0; 
           int l2_val = (l2!=null) ? l2.val:0; 
            
            int current_sum = l1_val + l2_val + carry;
            carry = current_sum/10;
            int last_digit = current_sum%10;
            ListNode new_node = new ListNode(last_digit); 
            l3.next = new_node;
            
            l1 = (l1!=null)? l1.next:l1;
            l2 = (l2!=null)? l2.next:l2;
            l3 = l3.next;
        }
        if(carry>0){
            ListNode new_node = new ListNode(1);
            l3.next = new_node;
            l3=l3.next;
        }
        return dummy_head.next;
    }
}
