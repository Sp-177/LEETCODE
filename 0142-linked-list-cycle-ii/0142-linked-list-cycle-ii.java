/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int val) { this.val = val; this.next = null; }
 * }
 */

class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null;
        }
        ListNode t = head;
        ListNode h = head;
        boolean flag = false;
        while (h != null && h.next != null) {
            t = t.next;
            h = h.next.next;
            if (h == t) {
                flag = true;
                break;
            }
        }
        if (flag) {
            t = head;
            while (t != h) {
                t = t.next;
                h = h.next;
            }
            return t;
        }
        return null;
    }
}
