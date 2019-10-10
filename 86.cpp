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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;
        ListNode *dummy=new ListNode(-1);
        ListNode *less, *greater, *cur, *pre;
        less=new ListNode(-1);greater=new ListNode(-1);
        dummy->next=head;
        pre=dummy;
        ListNode *lesspre, *greaterpre;
        lesspre=less;greaterpre=greater;
        
        while (pre->next){
            cur=pre->next;
            if (cur->val<x){
                lesspre->next=cur;
                lesspre=lesspre->next;
            }else{
                greaterpre->next=cur;
                greaterpre=greaterpre->next;
            }
            pre=pre->next;
        }
        lesspre->next=greater->next;
        greaterpre->next=NULL;
        return less->next;
    }
};