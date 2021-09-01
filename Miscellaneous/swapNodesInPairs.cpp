class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode* tmp=head->next->next;
        head->next->next=head;
        head=head->next;
        head->next->next=swapPairs(tmp);
        return head;
    }
};