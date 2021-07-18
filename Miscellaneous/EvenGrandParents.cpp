using namespace std;
#include <bits/stdc++.h>
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int sum=0;
        if(root->val%2==0)
        {
            if(root->left!=NULL&&root->left->left!=NULL)
            {
                sum+=root->left->left->val;
            }
            if(root->left!=NULL&&root->left->right!=NULL)
            {
                sum+=root->left->right->val;
            }
            if(root->right!=NULL&&root->right->left!=NULL)
            {
                sum+=root->right->left->val;
            }
            if(root->right!=NULL&&root->right->right!=NULL)
            {
                sum+=root->right->right->val;
            }
        }
        sum+=sumEvenGrandparent(root->left);
        sum+=sumEvenGrandparent(root->right);
        return sum;
    }
TreeNode* createBinaryTree()
{
    TreeNode* root=NULL;
    cout<<"Enter data: "<<"\n";
    int num;
    cin>>num;
    if(num==-1){
        return NULL;
    }
    root = new TreeNode();
    root->val=num;
    cout<<"Enter left for "<<num<<"\n";
    root->left=createBinaryTree();
    cout<<"Enter right for "<<num<<"\n";
    root->right=createBinaryTree();
    return root;
}
int main()
{
    TreeNode* root=createBinaryTree();
    cout<<sumEvenGrandparent(root);
}
