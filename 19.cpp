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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        ListNode *l,*r;
        l=r=head;
        for (int i=0;i<n;i++) r=r->next;
        if (!r) return head->next;
        while (r->next){
            l=l->next;
            r=r->next;
        }
        l->next=l->next->next;
        return head;
    }
};