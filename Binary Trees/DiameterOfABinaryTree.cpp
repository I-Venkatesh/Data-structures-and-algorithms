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
    for(string str; iss>>str;)
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
int dfs(Node* root,int* maxi)
{
    if(root==NULL)
    {
        return 0;
    }
    int l=dfs(root->left,maxi);
    int r=dfs(root->right,maxi);
    if(1+l+r>*maxi)
    {
        *maxi=1+l+r;
    }
    return 1+max(l,r);
}
int diameter(Node* root) {
    int maxi=0;
    dfs(root,&maxi);
    return maxi;
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
        cout<<diameter(root);
    }
}
