/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int len=0;
        ListNode* temp=head;
        ListNode* first=NULL;
        ListNode* second=NULL;
        while(temp)
        {
            len++;
            temp=temp->next;
        }
        if(len==1)
        {
            return true;
        }
        else if(len==2)
        {
            return head->val==head->next->val;
        }
        else if(len==3)
        {
            return head->val==head->next->next->val;
        }
        temp=NULL;
        first=head;
        second=first->next;
        if(len%2==0)
        {
            for(int i=0;i<len/2;i++)
            {
                first->next=temp;
                temp=first;
                first=second;
                second=second->next;
            }
            // cout<<first->val<<" "<<temp->val;
            while(first&&temp)
            {
                if(first->val!=temp->val)
                {
                    return 0;
                }
                first=first->next;
                temp=temp->next;
            }
        }
        else{
            for(int i=0;i<len/2;i++)
            {
                first->next=temp;
                temp=first;
                first=second;
                second=second->next;
            }
            // cout<<temp->val<<" "<<second->val;
            while(second&&temp)
            {
                if(second->val!=temp->val)
                {
                    return 0;
                }
                second=second->next;
                temp=temp->next;
            }
        }
        return 1;
    }
};