using namespace std;
#include<bits/stdc++.h>
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
Node* createNode(int val)
{
    Node* temp=new Node;
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
Node* buildTree(string s)
{
    if(s.size()==0||s[0]=='N')
    {
        return NULL;
    }
    istringstream iss(s);
    vector<string> t;
    while(iss>>s)
    {
        t.push_back((s));
    }
    queue<Node*> q;
    Node* root=createNode(stoi(t[0]));
    q.push(root);
    int i=1;
    while(!q.empty()&&i<t.size())
    {
        Node* currNode=q.front();
        q.pop();
        string currVal=t[i];
        if(currVal!="N")
        {
            currNode->left=createNode(stoi(currVal));
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
            currNode->right=createNode(stoi(currVal));
            q.push(currNode->right);
        }
        i++;
    }
    return root;
}
void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void recursive(Node* root)
{
    stack<Node*> st;
    Node* curr=root;
    while(!st.empty()||curr!=NULL)
    {
        if(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
           
        }
        else{
            curr=st.top();
            cout<<curr->data<<" ";
            st.pop();
            curr=curr->right;
        }
    }
}
int main()
{
    string s;
    getline(cin,s);
    Node* root=buildTree(s);
    inorder(root); 
    cout<<"\n";
    recursive(root);
}
