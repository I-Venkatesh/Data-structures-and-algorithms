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
vector<int> ans;
void left(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left)
    {
        ans.push_back(root->data);
        left(root->left);
    }
    else if(root->right){
        ans.push_back(root->data);
        left(root->right);
    }
}
void leafLeft(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    leafLeft(root->left);
    if(root->left==NULL&&root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    leafLeft(root->right);
}

void Right(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    if(root->right)
    {
        Right(root->right);
        ans.push_back(root->data);
        
    }
    else if(root->left){
        Right(root->left);
        ans.push_back(root->data);
    }
}
void sum(Node* root,int level,int* maxLevel,int s,int* maxSum)
{
    if(!root)
    {
        if(level>*maxLevel)
        {
            *maxLevel=level;
            if(s>*maxSum)
            {
                *maxSum=s;
            }
        }
        else if(level==*maxLevel)
        {
            if(s>*maxSum)
            {
                *maxSum=s;
            }
        }
        return;
    }
    sum(root->left,level+1,maxLevel,root->data+s,maxSum);
    sum(root->right,level+1,maxLevel,root->data+s,maxSum);
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
    int level=0,maxLevel=0,s=0,maxSum=0;
    cout<<sum(root,level,&maxLevel,s,&maxSum);
}
