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
vector<int> levelOrder(Node* node)
{
  //Your code here
  vector<int> ans;
  queue<Node*> q;
  q.push(node);
  while(!q.empty())
  {
      Node* p=q.front();
      if(p!=NULL)
      {
        ans.push_back(p->data);
      }
      q.pop();
      if(p!=NULL)
      {
          q.push(p->left);
          q.push(p->right);
      }
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
    vector<int> ans=levelOrder(root); 
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0; 
} 