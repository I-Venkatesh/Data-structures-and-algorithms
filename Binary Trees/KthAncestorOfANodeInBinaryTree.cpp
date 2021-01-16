using namespace std;
#include <bits/stdc++.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *createNode(int val)
{
    struct Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node *buildTree(vector<int> n)
{
    if (n.size() == 0 || n[0] == -1)
    {
        return NULL;
    }
    queue<Node *> q;
    Node *root = createNode(n[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < n.size())
    {
        Node *currNode = q.front();
        q.pop();
        if (n[i] != -1)
        {
            currNode->left = createNode(n[i]);
            q.push(currNode->left);
            i++;
        }
        if (i >= n.size())
        {
            break;
        }
        Node *curr = createNode(n[i]);
        if (n[i] != -1)
        {
            currNode->right = curr;
            q.push(currNode->right);
            i++;
        }
    }
    return root;
}
int ans;
Node *Kth(Node *root, int num,int &k)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == num||Kth(root->left,num,k)||Kth(root->right,num,k))
    {
        if(k>0)
        {
            k--;
        }
        else if(k==0)
        {
            ans=root->data;
            return NULL;
        }
        return root;
    }
    return NULL;
}
int main()
{
    int nodes, num, k;
    cin >> nodes >> num >> k;
    vector<int> n;
    for (int i = 0; i < nodes; i++)
    {
        int x;
        cin >> x;
        n.push_back(x);
    }
    Node *root = buildTree(n);
    ans=0;
    Kth(root, num,k);
    if(ans!=0)
    {
        cout<<ans<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }
}