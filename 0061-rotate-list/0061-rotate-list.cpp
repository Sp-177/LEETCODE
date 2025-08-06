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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        if(n==0)return head;
        k%=n;
        if(k==0)return head;
        int index=n-k+1;
        ListNode* newHead=head;
        for(int i=1;i<index-1;i++){
            newHead=newHead->next;
        }
        ListNode* tail=newHead;
        newHead=tail->next;
        tail->next=NULL;
        ListNode* newTail=newHead;
        while(newTail->next){
            newTail=newTail->next;
        }
        newTail->next=head;
        return newHead;
    }
};