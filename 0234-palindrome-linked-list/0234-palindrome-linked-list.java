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
    public boolean isPalindrome(ListNode head) {
        StringBuilder check = new StringBuilder();
        while (head != null) {
            check.append(head.val);
            head = head.next;
        }
        int i = -1, j = check.length();
        while (++i < --j) {
            if (check.charAt(i) != check.charAt(j)) {
                return false;
            }
        }
        return true;
    }
}