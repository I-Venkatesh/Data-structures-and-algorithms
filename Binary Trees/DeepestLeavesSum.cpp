/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=1+dfs(root->left);
        int right=1+dfs(root->right);
        return max(left,right);
    }
    int getMax(TreeNode* root,int level,int max)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(level==max)
        {
            return root->val;
        }
        int left=getMax(root->left,level+1,max);
        int right=getMax(root->right,level+1,max);
        return left+right;
    }
    int deepestLeavesSum(TreeNode* root) {
        int max=dfs(root);
        int ans=getMax(root,1,max);
        return ans;
    }
};