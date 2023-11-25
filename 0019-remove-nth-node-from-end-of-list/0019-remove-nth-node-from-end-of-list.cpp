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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next){delete head; return NULL;}
        ListNode* nh=head;
        int size=0;
        while(nh){
            size++;
            nh=nh->next;
        }
        ListNode* temp=head;
        if(size-n==0){
            return temp->next;}
        for(int i=1;i<size-n;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
        
        
    }
};