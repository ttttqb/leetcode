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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head||!head->next) return head;
        ListNode* newhead=new ListNode(0);
        ListNode *cur,*nxt;
        newhead->next=head;
        cur=newhead;
        //nxt=head->nxt;
        while (cur->next){
            nxt=cur->next;
            while (nxt->next && nxt->val==nxt->next->val) nxt=nxt->next;
            if (nxt!=cur->next) cur->next=nxt->next;
            else cur=cur->next;
        }
        return newhead->next;
    }
};