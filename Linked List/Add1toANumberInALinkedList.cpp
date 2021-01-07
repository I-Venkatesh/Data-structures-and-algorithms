#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    } 
};
node* addOne(node *&head) 
{
    node* prev=NULL;
    node* current=head;
    node* next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    node* temp=head;
    int carry=1;
    node* back=NULL;
    while(temp!=NULL)
    {
        int s=carry+(temp->data%10);
        int rem=s%10;
        temp->data=rem;
        carry=s/10;
        back=temp;
        temp=temp->next;
    }
    if(carry)
    {
        node* n=new node(carry);
        back->next=n;
    }
    prev=NULL;
    current=head;
    next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}
void insert(node* &head, int val)
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
    insert(head,9);
    insert(head,9);
    addOne(head);
    display(head);
}