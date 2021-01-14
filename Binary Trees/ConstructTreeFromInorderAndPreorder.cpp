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
int preIndex=0;
Node* buildTree(int in[],int pre[],int preS,int preE,int s)
{
    if(preS>preE)
    {
        return NULL;
    }
    Node* tempNode=createNode(pre[preIndex++]);
    if(preS==preE)
    {
        return tempNode;
    }   
    int inIndex;
    for(int i=0;i<s;i++)
    {
        if(in[i]==tempNode->data){
            inIndex=i;
            break;
        }
    }
    tempNode->left=buildTree(in,pre,preS,inIndex-1,s);
    tempNode->right=buildTree(in,pre,inIndex+1,preE,s);
    return tempNode;
}
void preorder(Node* root) 
{ 
    if (root == NULL) 
        return; 
    printf("%d ", root->data); 
    preorder(root->left); 
    preorder(root->right); 
} 
int main()
{
    int pre[4]={1,6,7,8};
    int inorder[4]={1,6,8,7};
    Node* root=buildTree(inorder,pre,0,3,4);
    preorder(root);
}
