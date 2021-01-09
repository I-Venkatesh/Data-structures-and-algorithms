#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insert(Node *&head, int val)
{
    Node *n = new Node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
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
int getNthFromLast(Node *head, int n)
{
       // Your code here
       int len=0;
       Node* temp=head;
       while(temp!=NULL)
       {
           len++;
           temp=temp->next;
       }
       int loop=len-n;
       if(loop<0)
       {
           return -1;
       }
       else{
           temp=head;
           while(loop)
           {
               temp=temp->next;
               loop--;
           }
           return temp->data;
       }
}
int main()
{
    Node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    cout<<getNthFromLast(head,2)<<"\n";
    // display(head);
}