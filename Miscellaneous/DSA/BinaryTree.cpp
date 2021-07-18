using namespace std;
#include<bits/stdc++.h>
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};
TreeNode* createTreeDepthWise()
{
    int num;
    TreeNode* root=NULL;
    cout<<"Enter Data: ";
    cin>>num;
    if(num==-1)
    {
        return NULL;
    }
    root=new TreeNode();
    root->val=num;
    cout<<"Enter Data left to the: "<<num<<"\n";
    root->left=createTreeDepthWise();
    cout<<"EnterData right to the: "<<num<<"\n";
    root->right=createTreeDepthWise();
    return root;
}
TreeNode* createTreeBreadthWise(int arr[],TreeNode* root,int i,int n)
{
    if(i<n)
    {
        TreeNode* temp=new TreeNode();
        temp->val=arr[i];
        root=temp;
        root->left=createTreeBreadthWise(arr,root->left,2*i+1,n);
        root->right=createTreeBreadthWise(arr,root->right,2*i+2,n);
    }
    return root;
}
void printInorder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    printInorder(root->left);
    cout<<root->val;
    printInorder(root->right);
}
int main()
{
    TreeNode* root=createTreeDepthWise();
    printInorder(root);
    int arr[3]={1,2,3};
    TreeNode* root2=createTreeBreadthWise(arr,root2,0,3);
    printInorder(root2);
}

