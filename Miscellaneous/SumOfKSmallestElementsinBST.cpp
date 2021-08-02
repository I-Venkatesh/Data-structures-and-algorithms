int helper(Node* root,int k,int& count)
{
    if(root==NULL)
    {
        return 0;
    }
    if(count>k)
    {
        return 0;
    }
    int res=helper(root->left,k,count);
    if(count>=k)
    {
        return res;
    }
    res+=root->data;
    count++;
    if(count>=k)
    {
        return res;
    }
    return res+helper(root->right,k,count);
}
int sum(Node* root, int k) 
{ 
    int count=0;
    return helper(root,k,count);
} 