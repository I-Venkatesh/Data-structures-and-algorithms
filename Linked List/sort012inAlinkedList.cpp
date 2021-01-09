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
Node* segregate(Node *head) {
    
    // Add code here
    int zero=0,one=0,two=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zero++;
        }
        else if(temp->data==1)
        {
            one++;
        }
        else{
            two++;
        }
        temp=temp->next;
    }
    temp=head;
    while(zero)
    {
        temp->data=0;
        temp=temp->next;
        zero--;
    }
    while(one)
    {
        temp->data=1;
        temp=temp->next;
        one--;
    }
    while(two)
    {
        temp->data=2;
        temp=temp->next;
        two--;
    }
    return head;
}
int main()
{
    Node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 2);
    insert(head, 0);
    insert(head, 0);
    cout<<segregate(head)<<"\n";
    display(head);
}