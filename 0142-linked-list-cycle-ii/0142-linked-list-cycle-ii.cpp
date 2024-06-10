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
    ListNode *detectCycle(ListNode *head) {
        if(!head ||!head->next){return NULL;}
        ListNode* t=head;
        ListNode* h=head;
        bool flg=false;
        while(h&&h->next){
            t=t->next;
            h=h->next->next;
            if(h==t){flg=true;break;}
        }
        if(flg){
            t=head;
            while(t!=h){
                t=t->next;
                h=h->next;
            }
            return t;
        }
        return NULL;
    }
};