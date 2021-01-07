#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    } 
};
struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    struct Node* head=first;
    struct Node* prev=NULL;
    struct Node* current=head;
    struct Node* next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    
    struct Node* head2=second;
    struct Node* prev2=NULL;
    struct Node* current2=head2;
    struct Node* next2=NULL;
    while(current2!=NULL)
    {
        next2=current2->next;
        current2->next=prev2;
        prev2=current2;
        current2=next2;
    }
    head2=prev2;
    
    int carry=0;
    struct Node* a=head,*b=head2;
    struct Node* h=NULL;
    while(a&&b)
    {
        int s=carry+((a->data+b->data));
        int rem=s%10;
        Node* n=new Node(rem);
        if(h==NULL)
        {
            h=n;
        }
        else{
            struct Node* f=h;
            while(f->next!=NULL)
            {
                f=f->next;
            }
            f->next=n;
        }
        carry=s/10;
        a=a->next;
        b=b->next;
    }
    while(a)
    {
        struct Node* f=h;
        int s=carry+(a->data);
        int rem=s%10;
        Node* n=new Node(rem);
        while(f->next!=NULL)
        {
            f=f->next;
        }
        f->next=n;
        a=a->next;
        carry=s/10;
    }
    while(b)
    {
        struct Node* f=h;
        int s=carry+(b->data);
        int rem=s%10;
        Node* n=new Node(rem);
        while(f->next!=NULL)
        {
            f=f->next;
        }
        f->next=n;
        b=b->next;
        carry=s/10;
    }
    while(carry)
    {
        Node* n=new Node(carry%10);
        struct Node* f=h;
        while(f->next!=NULL)
        {
            f=f->next;
        }
        f->next=n;
        carry/=10;
    }
    prev=NULL;
    current=h;
    next=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    h=prev;
    return h;
}

void insert(Node* &head, int val)
{
    Node* n=new Node(val);
    if(head==NULL)
    {
        head=n;
        return;
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
     }
}
void display(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    Node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);

    Node* head2=NULL;
    insert(head2,1);
    insert(head2,2);
    insert(head2,3);
    insert(head2,4);
    insert(head2,5);
    
    Node* x=addTwoLists(head,head2);
    display(x);
}