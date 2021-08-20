class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            if(curr->next!=NULL&&curr->val==curr->next->val)
            {
                while(curr->next!=NULL&&curr->val==curr->next->val)
                {
                    curr=curr->next;
                }
                if(prev==NULL)
                {
                    head=curr->next;
                    prev=NULL;
                }
                else{
                    prev->next=curr->next;
                }
                curr=curr->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};