#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insert(node* &head,int val)
{
    node* temp=head;
    node* n=new node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
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
bool detectLoop(node* head)
{
    struct node* temp1=head,*temp2=head;
    while(temp1&&temp2&&temp2->next)
    {
        temp1=temp1->next;
        temp2=temp2->next->next;
        if(temp1==temp2)
        {
            return 1;
        }
    }
    return 0;
   
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
    // display(head);
    if(detectLoop(head))
    {
        cout<<"Loop found"<<"\n";
    }
    else{
        cout<<"No loop found"<<"\n";
    }
}
