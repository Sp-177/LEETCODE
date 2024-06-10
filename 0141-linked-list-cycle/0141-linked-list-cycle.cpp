/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next){return false;}
        ListNode* h=head;
        ListNode* t=head;
        while(h&&h->next){
            t=t->next;
            h=h->next->next;
            if(h==t){return true;}
        }
        return false;
    }
};