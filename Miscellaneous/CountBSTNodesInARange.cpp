//Function to count number of nodes in BST that lie in the given range.
int maxi;
int helper(Node* root,int l,int h)
{
    if(root==NULL)
    {
        return 0;    
    }
    if(root->data>=l&&root->data<=h)
    {
        return 1+helper(root->left,l,h)+helper(root->right,l,h);
    }
    else if(root->data>h)
    {
        helper(root->left,l,h);
    }
    else
    {
        helper(root->right,l,h);
    }
}
int getCount(Node *root, int l, int h)
{
    return helper(root,l,h);
}