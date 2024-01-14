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
    ListNode* func(ListNode* head1,ListNode* head2){
        if(!head1)return head2;
        else if(!head2)return head1;
        ListNode* head;
        if(head1->val>head2->val){head=head2;head2=head2->next;}
        else{head=head1;head1=head1->next;}
        ListNode* tail=head;
        while(head1&&head2){
            if(head1->val<head2->val){
                tail->next=head1;
                tail=head1;
                head1=head1->next;
            }
            else{
                tail->next=head2;
                tail=head2;
                head2=head2->next;
            }
        }
        if(head1)tail->next=head1;
        if(head2)tail->next=head2;
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        for(auto i:lists){
            head=func(head,i);
        }
        return head;
    }
};