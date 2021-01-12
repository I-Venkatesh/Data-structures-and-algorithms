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
void postorder(Node* root){
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void recursive(Node* root)
{
    stack<Node*> in;
    stack<Node*> out;
    Node* curr=root;
    while(!in.empty())
    {
        Node* curr=in.top();
        in.pop();
        out.push(curr);
        if(curr->left!=NULL)
        {
            in.push(curr->left);
        }
        if(curr->right!=NULL)
        {
            in.push(curr->right);
        }
    }
    while(!out.empty())
    {
        cout<<out.top()->data<<" ";
        out.pop();
    }
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
    postorder(root);
    cout<<"\n";
    recursive(root);
}
