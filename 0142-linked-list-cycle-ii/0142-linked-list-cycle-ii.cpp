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
        ListNode* fast=head,*slow=head;
        while(fast){
            fast=fast->next;
            if(fast)fast=fast->next;
            else return NULL;
            slow=slow->next;
            if(fast==slow)break;
        }
        if(!fast)return NULL;
        ListNode* entry=head;
        while(entry!=slow){
            entry=entry->next;
            slow=slow->next;
        } 
        return entry;
    }
};