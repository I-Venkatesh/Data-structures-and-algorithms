class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head||!head->next)
        {
            return head;
        }
        int c=0;
        ListNode* cur=head,*prev=NULL,*nxt;
        while(cur)
        {
            if(++c==left)
            {
                ListNode *rtail=prev,*lhead=cur;
                while(c<=right)
                {
                    nxt=cur->next;
                    cur->next=prev;
                    prev=cur;
                    cur=nxt;
                    c++;
                }
                if(rtail==NULL)
                {
                    head=prev;
                }
                else
                {
                    rtail->next=prev;
                }
                lhead->next=cur;
                return head;
            }
            prev=cur;
            cur=cur->next;
        }
        return head;
    }
};