/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode temp = new ListNode(0);
        ListNode current_node = temp; 
            
            while(true){
            if(l1 == null)
            {
                current_node.next = l2;
                break;
            }
            else if(l2 == null)
            {
                current_node.next = l1;
                break;
            }
            else if(l1.val < l2.val)
            {
                current_node.next = l1;
                l1 = l1.next;
            }
            else if(l1.val >= l2.val)
            {
                current_node.next = l2;
                l2 = l2.next;
            }
            
            current_node = current_node.next;
            }
        return temp.next;
    }
}
