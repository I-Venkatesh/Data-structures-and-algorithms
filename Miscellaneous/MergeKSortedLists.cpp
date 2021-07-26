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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        {
            return NULL;
        }
        int j=0;
        while(j<lists.size()&&lists[j]==NULL)
        {
            j++;
        }
        if(j==lists.size())
        {
            return NULL;
        }
        for(int i=j+1;i<lists.size();i++)
        {
            ListNode* first=lists[j];
            ListNode* l=lists[i];
            if(l==NULL)
            {
                continue;
            }
            if(first->val<=l->val)
            {
                while(l!=NULL)
                {
                    if(first->next!=NULL&&first->next->val<l->val)
                    {
                        first=first->next;
                    }
                    else
                    {
                        ListNode* temp1=first->next;
                        ListNode* temp2=l->next;
                        first->next=l;
                        first->next->next=temp1;
                        l=temp2;
                    }
                }
            }
            else if(first!=NULL)
            {
                first=lists[i];
                l=lists[j];
                while(l!=NULL)
                {
                    if(first->next!=NULL&&first->next->val<l->val)
                    {
                        first=first->next;
                    }
                    else
                    {
                        ListNode* temp1=first->next;
                        ListNode* temp2=l->next;
                        first->next=l;
                        first->next->next=temp1;
                        l=temp2;
                    }
                }
                lists[j]=lists[i];
            }
        }
        return lists[j];
    }
};