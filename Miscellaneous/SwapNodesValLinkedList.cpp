class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int len=0;
        ListNode* temp=head;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        int loop1=k-1;
        int loop2=len-k;
        ListNode* t1=head;
        for(int i=0;i<loop1;i++)
        {
            t1=t1->next;
        }
        ListNode* t2=head;
         for(int i=0;i<loop2;i++)
        {
            t2=t2->next;
        }
        int cache=t1->val;
        t1->val=t2->val;
        t2->val=cache;
        return head;
    }
};