using namespace std;
#include <bits/stdc++.h>
class Node
{
public:
    int val;
    Node *next;
};
bool checkCycle(Node *head)
{
    Node *a = NULL;
    if (head != NULL)
    {
        a = head;
    }
    else
    {
        return false;
    }
    Node *b = NULL;
    if (head->next != NULL)
    {
        b = head->next;
    }
    else
    {
        return false;
    }
    while (a != NULL && b != NULL)
    {
        if (a == b)
        {
            return true;
        }
        a = a->next;
        if (b->next != NULL)
        {
            b = b->next->next;
        }
        else
        {
            return false;
        }
    }
    return false;
}
int main()
{
    int num;
    cin >> num;
    Node *root = NULL;
    for (int i = 0; i < num-1; i++)
    {
        if (root == NULL)
        {
            Node *n = new Node();
            cin >> n->val;
            n->next = NULL;
            root=n;
        }
        else
        {
            Node *n = new Node();
            cin >> n->val;
            n->next = NULL;
            Node *temp = root;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }
    Node *n = new Node();
    cin >> n->val;
    n->next = root;
    Node *temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next=n;
    cout << checkCycle(root) << "\n";
}