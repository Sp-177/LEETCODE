/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string check="";
        while(head){
            check+=to_string(head->val);
            head=head->next;
        }
        int i=-1,j=check.size();
        while(i++<j--)if(check[i]!=check[j])return false;
        return true;
    }
};