using namespace std;
#include<bits/stdc++.h>
struct ListNode{
    int val;
    ListNode* next;
};
int main()
{
    int num;
    cin>>num;
    struct ListNode *root=NULL;
    for(int i=0;i<num;i++)
    {
        if(root==NULL)
        {
            struct ListNode *n=(struct  ListNode*)malloc(sizeof(struct  ListNode*));
            cin>>n->val;
            n->next=NULL;
            root=n;
        }
        else{
            struct ListNode *temp=root;
            struct ListNode *n=(struct ListNode*)malloc(sizeof(struct ListNode*));
            cin>>n->val;
            n->next=NULL;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=n;
        }
    }
    struct ListNode* a=NULL;
    struct ListNode* b=root;
    struct ListNode* c=root->next;
    while(b)
    {
        b->next=a;
        a=b;
        b=c;
        if(c==NULL)
        {
            break;
        }
        c=c->next;
        
    }
    while(a)
    {
        cout<<a->val<<" ";
        a=a->next;
    }
}