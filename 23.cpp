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
    class cmp{
        public:
        bool operator() (ListNode *a, ListNode *b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (int i=0;i<lists.size();i++){
            if (lists[i]!=NULL)
                q.push(lists[i]);
        }
        ListNode *h,*prev,*t;
        h=NULL;
        prev=NULL;
        while (!q.empty()){
            t=q.top();
            q.pop();
            if (!prev) h=t;
            else prev->next=t;
            prev=t;
            if (t->next!=NULL) q.push(t->next);
        }
        return h;
    }
};