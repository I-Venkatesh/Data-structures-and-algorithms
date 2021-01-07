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
node *removeDuplicates(node* head)
{
    unordered_set<int> seen;
    node* current=head;
    node* prev=NULL;
    while(current!=NULL)
    {
        if(seen.find(current->data)!=seen.end())
        {
            prev->next=current->next;
            delete(current);
        }
        else{
            seen.insert(current->data);
            prev=current;
        }
        current=prev->next;
    }
    return head;
}
int main()
{
    node* head=NULL;
    insert(head,2);
    insert(head,2);
    insert(head,2);
    insert(head,2);
    insert(head,50);
    insert(head,60);
    insert(head,60);
    insert(head,80);
    node* ans=removeDuplicates(head);
    display(ans);
}