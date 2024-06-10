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
        map<ListNode*,int>m;
        ListNode* t=head;
        while(t){
            if(m[t]>0){return t;}
            m[t]=1;
            t=t->next;
        }
        return NULL;
    }
};