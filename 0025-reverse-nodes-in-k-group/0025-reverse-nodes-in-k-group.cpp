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
    int len(ListNode* head) {
        ListNode* tail = head;
        int cnt = 0;
        while (tail) {
            tail = tail->next;
            cnt++;
        }
        return cnt;
    }

    pair<ListNode*, ListNode*> rev(ListNode* head, int index, int k, int n) {
        if (index + k > n) return { head, NULL };

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextHead = nullptr;

        for (int i = 0; i < k; i++) {
            // cout<<(prev?prev->val:-1)<<" "<<(curr?curr->val:-1)<<" "<<(nextHead?nextHead->val:-1)<<endl;
            nextHead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextHead;
        }
        return { prev, curr};  
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 0 || k == 1 || !head->next) return head;

        int n = len(head);
        int index = 0;

        pair<ListNode*, ListNode*> firstRev = rev(head, index, k, n);
        ListNode* mainHead = firstRev.first;
        ListNode* newHead = firstRev.second;
        ListNode* mainTail = head;

        index += k;

        while (newHead) {
            pair<ListNode*, ListNode*> nextRev = rev(newHead, index, k, n);
            mainTail->next = nextRev.first;
            mainTail = newHead;
            newHead = nextRev.second;
            index += k;
        }

        return mainHead;
    }
};
