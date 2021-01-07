using namespace std;
#include<bits/stdc++.h>
class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
    }
};
void insert(node* &head,int val)
{
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
}
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void removeLoop(node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return;
    }
    node* slow=head,*fast=head;
    while(slow&&fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            break;
        }
    }
    if(slow!=fast)
    {
        return;
    }
    else if(slow==fast)
    {
        if(slow==head)
        {
            node* temp=head;
            while(temp->next!=fast)
            {
                temp=temp->next;
            }
            temp->next=NULL;
        }
        else{
            slow=head;
            while(slow->next!=fast->next)
            {
                if(slow->next==fast->next)
                {
                    fast->next=NULL;
                }
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
        }
    }
    return;
}
int main()
{
    node* head=NULL;
    insert(head,10);
    insert(head,20);
    insert(head,30);
    insert(head,40);
    insert(head,50);
    insert(head,60);
    insert(head,70);
    insert(head,80);
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    removeLoop(head);
    display(head);
}