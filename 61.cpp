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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* i=head, *h, *t, *temp;
        if (head==NULL) return NULL;
        int len=1;
        while (i->next!=NULL) {
            i=i->next;
            len++;
        }
        k%=len;
        if (k==0) return head;
        h=head;t=i;
        t->next=h;
        for (int i=0;i<len-k-1;i++) h=h->next;
        temp=h->next;
        t=h;
        h=temp;
        t->next=NULL;
        return h;
    }
};
