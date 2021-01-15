using namespace std;
#include<bits/stdc++.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
Node* createNode(int val)
{
    struct Node* temp=new Node;
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
Node* buildTree(vector<int> n)
{
    if(n.size()==0||n[0]==-1)
    {
        return NULL;
    }
    queue<Node*> q;
    Node* root=createNode(n[0]);
    q.push(root);
    int i=1;
    while(!q.empty()&&i<n.size())
    {
        Node* currNode=q.front();
        q.pop();
        if(n[i]!=-1)
        {
            currNode->left=createNode(n[i]);
            q.push(currNode->left);
            i++;
        }
        if(i>=n.size())
        {
            break;
        }
        Node* curr=createNode(n[i]);
        if(n[i]!=-1)
        {
            currNode->right=curr;
            q.push(currNode->right);
            i++;
        }
    }
    return root;
}

void mirror(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left,root->right);
}
bool check(Node* root1,Node* root2)
{
    queue<Node*> q1,q2;
    q1.push(root1);
    q2.push(root2);
    while(!q1.empty()&&!q2.empty())
    {
        Node* a=q1.front();
        q1.pop();
        Node* b=q2.front();
        q2.pop();
        if(a->data!=b->data)
        {
            return false;
        }
        if(a->left!=NULL)
        {
            q1.push(a->left);
        }
        if(a->right!=NULL)
        {
            q1.push(a->right);
        }
        if(b->left!=NULL)
        {
            q2.push(b->left);
        }
        if(b->right!=NULL)
        {
            q2.push(b->right);
        }
    }
    return true;
}
bool isIsomorphic(Node *root1,Node *root2)
{
    Node* temp1=root1,*temp2=root2;
    if(check(temp1,temp2))
    {
        return true;
    }
    mirror(root2);
    return check(root1,root2);
}
int main()
{
    int nodes;
    cin>>nodes;
    vector<int> n,n2;
    for(int i=0;i<nodes;i++)
    {
        int x;
        cin>>x;
        n.push_back(x);
    }
    for(int i=0;i<nodes;i++)
    {
        int x;
        cin>>x;
        n2.push_back(x);
    }
    Node* root=buildTree(n);
    Node* root2=buildTree(n2);
    cout<<isIsomorphic(root,root2);
}
