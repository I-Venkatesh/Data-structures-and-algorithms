class Solution {
public:
    ListNode* solve(ListNode* head)
    {
        if(head==NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            return head;
        }
        ListNode* temp=head;
        ListNode* temp2=head->next;
        while(temp->next&&temp->next->next)
        {
            temp=temp->next;
        }
        head->next=temp->next;
        temp->next=NULL;
        if(temp2&&head->next&&&head->next->next)
        {
            head->next->next=solve(temp2);
        }
        else{
            head->next=temp2;
        }
        return head;
    }
    void reorderList(ListNode* head) {
        solve(head);
    }
};