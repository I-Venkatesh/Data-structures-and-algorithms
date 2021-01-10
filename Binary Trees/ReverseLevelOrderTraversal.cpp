using namespace std;
#include <bits/stdc++.h>
class Node 
{ 
    public:
    int data; 
    Node* left, *right;
    Node(int d) 
    { 
        data = d; 
        left = NULL; 
        right = NULL; 
    }  
};
vector<int> reverseLevelOrder(Node *root)
{
   stack<Node*> st;
   queue<Node*> q;
   q.push(root);
   while(!q.empty())
   {
       Node* current=q.front();
       q.pop();
       if(current->right!=NULL)
       {
           q.push(current->right);
       }
       if(current->left!=NULL)
       {
           q.push(current->left);
       }
       st.push(current);
   }
   vector<int> ans;
   while(!st.empty())
   {
       ans.push_back(st.top()->data);
       st.pop();
   }
   return ans;
}
int main() 
{ 
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
 
    cout << "Level Order traversal of binary tree is \n"; 
    vector<int> ans=reverseLevelOrder(root); 
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0; 
} 