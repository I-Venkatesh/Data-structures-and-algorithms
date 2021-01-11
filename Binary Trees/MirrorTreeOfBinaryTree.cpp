using namespace std;
#include<bits/stdc++.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val)
{
    Node* temp=new Node;
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
Node* buildTree(string str)
{
    if(str.length()==0||str[0]=='N')
    {
        return NULL;
    }
    vector<string> t;
    istringstream iss(str);
    while(iss>>str)
    {
        t.push_back(str);
    }
    Node* root= newNode(stoi(t[0]));
    queue<Node*> q;
    q.push(root);
    int i=1;
    while(!q.empty()&&i<t.size())
    {
        Node* currNode=q.front();
        q.pop();
        string currVal=t[i];
        if(currVal!="N")
        {
            currNode->left=newNode(stoi(currVal));
            q.push(currNode->left);
        }
        i++;
        if(i>=t.size())
        {
            break;
        }
        currVal=t[i];
        if(currVal!="N")
        {
            currNode->right=newNode(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }
    return root;
}
void dfs(Node* root)
{
    if(root->left==NULL)
    {
        return;
    }
    dfs(root->left);
    dfs(root->right);
    swap(root->left,root->right);
}
void inorder(Node* root) 
{ 
    if (root == NULL) 
        return; 
    inorder(root->left); 
    printf("%d ", root->data); 
    inorder(root->right); 
} 
int main()
{
    int test;
    test=1;
    while(test--)
    {
        string s;
        getline(cin,s);
        Node* root=buildTree(s);
        inorder(root);
        dfs(root);
        cout<<"\n";
        inorder(root);
        
    }
}