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
bool isCircular(Node *head)
{
   Node* slow=head,*fast=head;
   while(fast&&fast->next)
   {
       slow=slow->next;
       fast=fast->next->next;
       if(slow==fast)
       {
           return 1;
       }
   }
   return 0;
}
int main()
{
    Node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    Node* temp=head;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=head;
    cout<<isCircular(head)<<"\n";
}