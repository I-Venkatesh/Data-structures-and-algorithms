using namespace std;
#include <bits/stdc++.h>
struct ListNode
{
    int val;
    ListNode *next;
};
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *n1;
    ListNode *n2;
    n1 = l1;
    n2 = l2;
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    if (n1->val <= n2->val)
    {
        while (n2)
        {
            if (n1->next != NULL && n1->next->val >= n2->val)
            {
                ListNode *temp = n1->next;
                ListNode *temp2 = n2;
                n2 = n2->next;
                temp2->next = NULL;
                n1->next = temp2;
                n1->next->next = temp;
                n1 = n1->next;
            }
            else
            {
                if (n1->next == NULL)
                {
                    n1->next = n2;
                    return l1;
                }
                n1 = n1->next;
            }
        }
        return l1;
    }
    else
    {
        while (n1)
        {
            if (n2->next != NULL && n2->next->val >= n1->val)
            {
                ListNode *temp = n2->next;
                ListNode *temp2 = n1;
                temp2->next = NULL;
                n1 = n1->next;
                n2->next = temp2;
                n2->next->next = temp;
                n2 = n2->next;
            }
            else
            {
                if (n2->next == NULL)
                {
                    n2->next = n1;
                    return l2;
                }
                n2 = n2->next;
            }
        }
        return l2;
    }
    return NULL;
}
int main()
{

    int num1;
    cout << "Number of elements for list1";
    cin >> num1;
    struct ListNode *root=NULL;
    for (int i = 0; i < num1; i++)
    {
        if (root == NULL)
        {
            struct ListNode *n1 = (struct ListNode *)malloc(sizeof(struct ListNode));
            cin >> n1->val;
            n1->next = NULL;
            root = n1;
        }
        else
        {
            struct ListNode *n1 = new ListNode();
            cin >> n1->val;
            n1->next = NULL;
            struct ListNode *temp = root;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n1;
        }
    }

    int num2;
    cout << "Number of elements for list1";
    cin >> num2;
    struct ListNode *root2=NULL;
    for (int i = 0; i < num2; i++)
    {
        if (root2 == NULL)
        {
            struct ListNode *n1 = (struct ListNode *)malloc(sizeof(struct ListNode));
            cin >> n1->val;
            n1->next = NULL;
            root2 = n1;
        }
        else
        {
            struct ListNode *n1 = new ListNode();
            cin >> n1->val;
            n1->next = NULL;
            struct ListNode *temp = root2;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n1;
        }
    }
    struct ListNode* ans=mergeTwoLists(root,root2);
    while(ans)
    {
        cout<<ans->val<<" ";
        ans=ans->next;
    }
}