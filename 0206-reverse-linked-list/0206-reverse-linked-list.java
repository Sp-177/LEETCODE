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
    public ListNode reverseList(ListNode head) {
        ListNode t = head;
        ListNode newHead = null;
        while (t != null) {
            ListNode n = t.next;
            t.next = newHead;
            newHead = t;
            t = n;
        }
        return newHead;
    }
}
