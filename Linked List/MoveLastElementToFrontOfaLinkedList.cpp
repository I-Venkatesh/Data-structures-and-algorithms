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
int main()
{
    node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node* hold=temp->next;
    temp->next=NULL;
    hold->next=head;
    head=hold;
    display(head);
}