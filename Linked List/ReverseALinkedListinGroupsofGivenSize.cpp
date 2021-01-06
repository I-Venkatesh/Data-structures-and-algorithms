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
struct node *reverse (struct node *head, int k)
{ 
    struct node* prev=NULL,*current=head,*next=NULL;
    int steps=k;
    while(current!=NULL&&steps>0)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        steps--;
    }
    if(next!=NULL)
    {
        head->next=reverse(next,k);
    }
    return prev;
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
    insert(head,10);
    insert(head,20);
    insert(head,30);
    insert(head,40);
    insert(head,50);
    insert(head,60);
    insert(head,70);
    insert(head,80);
    struct node* x=reverse(head,3);
    display(x);
}