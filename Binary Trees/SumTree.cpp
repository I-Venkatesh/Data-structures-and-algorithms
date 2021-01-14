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
bool isLeaf(Node* node)
{
    if(node==NULL)
    {
        return 0;
    }
    if(node->left==NULL&&node->right==NULL)
    {
        return 1;
    }
    return 0;
}
bool isSumTree(Node* node)
{
    int ls,rs;
    if(node==NULL||isLeaf(node))
    {
        return 1;
    }
    if(isSumTree(node->left)&&isSumTree(node->right))
    {
        if(node->left==NULL)
        {
            ls=0;
        }
        else if(isLeaf(node->left))
        {
            ls=node->left->data;
        }
        else{
            ls=2*node->left->data;
        }
        if(node->right==NULL)
        {
            rs=0;
        }
        else if(isLeaf(node->right))
        {
            rs=node->right->data;
        }
        else{
            rs=2*node->right->data;
        }
        return (node->data==(ls+rs));
    }
    return 0;
}
int main()
{
    int nodes;
    cin>>nodes;
    vector<int> n;
    for(int i=0;i<nodes;i++)
    {
        int x;
        cin>>x;
        n.push_back(x);
    }
    Node* root=buildTree(n);
    cout<<isSumTree(root);
}
