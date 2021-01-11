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
int height(Node* node){
    if(node==NULL)
    {
        return 0;
    }
    else{
        return 1+max(height(node->left),height(node->right));
    }
}
int main() 
{ 
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    cout<<height(root);
} 