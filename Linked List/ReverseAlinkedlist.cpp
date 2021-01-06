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
void iterativeMethod(node* &head)
{
    node* current=head,*prev=NULL,*next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
void recursionMethod(node* prev,node* current,node* next,node* &head){
    if(current==NULL)
    {
        head=prev;
        return;
    }
    else{
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        recursionMethod(prev,current,next,head);
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
    display(head);
    cout<<"\n";
    iterativeMethod(head);
    display(head);
    recursionMethod(NULL,head,NULL,head);
    cout<<"\n";
    display(head);
}