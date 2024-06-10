/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) { this.val = val; this.next = null; }
 * }
 */

class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode h = head;
        ListNode t = head;
        while (h != null && h.next != null) {
            t = t.next;
            h = h.next.next;
            if (h == t) {
                return true;
            }
        }
        return false;
    }
}
