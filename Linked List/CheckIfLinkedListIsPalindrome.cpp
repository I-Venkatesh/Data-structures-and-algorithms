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
bool isPalindrome(Node *head)
{
    //Your code here
    Node* head2=head;
    Node* current=head2;
    Node* prev=NULL;
    Node* next=NULL;
    int len=0;
    Node* temp=head;
    while(temp)
    {
        len++;
        temp=temp->next;
    }
    int x=len;
    len/=2;
    while(len>0)
    {
        len--;
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    if(x%2!=0)
    {
        current=current->next;
    }
    head2=prev;
    temp=current;
    Node* temp2=prev;
    while(temp)
    {
        if(temp2->data!=temp->data)
        {
            return 0;
        }
        temp2=temp2->next;
        temp=temp->next;
    }
    return 1;
}
int main()
{
    Node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    cout<<isPalindrome(head)<<"\n";
}