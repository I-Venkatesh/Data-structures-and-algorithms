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
Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    int freq[100000];
    memset(freq,0,sizeof(freq));
    Node* temp=head1;
    while(temp)
    {
        if(freq[temp->data]==0)
        {
            freq[temp->data]++;
        }
        temp=temp->next;
    }
    temp=head2;
    while(temp)
    {
        if(freq[temp->data]==1)
        {
            freq[temp->data]++;
        }
        temp=temp->next;
    }
    Node* h=NULL;
    for(int i=0;i<6999;i++)
    {
        if(freq[i]==2)
        {
            if(h==NULL)
            {
                Node *n=new Node(i);
                h=n;
            }
            else{
                 Node *n=new Node(i);
                Node* f=h;
                while(f->next!=NULL)
                {
                    f=f->next;
                }
                f->next=n;
            }
        }
    }
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
    
    Node* x=findIntersection(head,head2);
    display(x);
}