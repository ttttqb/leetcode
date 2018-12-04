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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *old_head, *prev, *now;
        int len;
        old_head=new ListNode(-1);
        old_head->next=head;
        now=old_head;
        len=0;
        while (now=now->next) len++;
        prev=old_head;
        while (len>=k){
            now=prev->next;
            for (int i=1;i<k;i++){
                ListNode *t=now->next;
                now->next=t->next;
                t->next=prev->next;
                prev->next=t;
            }
            prev=now;
            len-=k;
        }
        return old_head->next;
    }
};