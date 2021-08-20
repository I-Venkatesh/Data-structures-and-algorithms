class Solution {
public:
    int dfs(TreeNode* root,int maxi)
    {
        if(root==NULL)
        {
            return 0;
        }
        maxi=max(root->val,maxi);
        int a=dfs(root->left,maxi);
        int b=dfs(root->right,maxi);
        if(root->val>=maxi)
        {
            return 1+a+b;
        }
        return a+b;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};