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
node *removeDuplicates(node *root)
{
 // your code goes here
    node* temp=root;
    node* next=root->next;
    if(root==NULL)
    {
        return root;
    }
    while(temp&&temp->next)
    {
        while(temp->data==temp->next->data&&temp->next&&temp)
        {
            if(temp->next->next==NULL)
            {
                temp->next=NULL;
                break;
            }
            temp->next=temp->next->next;
        }
        temp=temp->next;
    }
    return root;
}
int main()
{
    node* head=NULL;
    insert(head,10);
    insert(head,10);
    insert(head,20);
    insert(head,20);
    insert(head,50);
    insert(head,60);
    insert(head,60);
    insert(head,80);
    removeDuplicates(head);
    display(head);
}