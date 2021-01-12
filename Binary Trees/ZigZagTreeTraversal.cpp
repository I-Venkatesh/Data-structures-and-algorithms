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
vector <int> zigZagTraversal(Node* root)
{
	// Code here
	stack<Node*> current;
	stack<Node*> nextLevel;
	vector<int> ans;
	current.push(root);
	while(!current.empty()||!nextLevel.empty())
	{
	    while(!current.empty())
	    {
	        Node* curr=current.top();
	        ans.push_back(curr->data);
	        current.pop();
	        if(curr->left!=NULL)
	        {
	            nextLevel.push(curr->left);
	        }
	        if(curr->right!=NULL)
	        {
	            nextLevel.push(curr->right);
	        }
	    }
	    while(!nextLevel.empty())
	    {
	        Node* curr=nextLevel.top();
	        ans.push_back(curr->data);
	        nextLevel.pop();
	        if(curr->right!=NULL)
	        {
	            current.push(curr->right);
	        }
	        if(curr->left!=NULL)
	        {
	            current.push(curr->left);
	        }
	        
	    }
	}
	return ans;
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
    vector<int> ans=zigZagTraversal(root);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}
