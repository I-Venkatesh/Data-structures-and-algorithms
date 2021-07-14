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
    TreeNode* helper(int l,int r,vector<int>& nums)
    {
        if(l>r)
        {
            return NULL;
        }
        if(l==r)
        {
            TreeNode* node=new TreeNode();
            node->val=nums[l];
            node->left=NULL;
            node->right=NULL;
            return node;
        }
        int maxi=-1,pos=-1;
        for(int i=l;i<=r;i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                pos=i;
            }
        }
        TreeNode* root=new TreeNode();
        root->val=nums[pos];
        root->left=helper(l,pos-1,nums);
        root->right=helper(pos+1,r,nums);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int maxi=-1,pos=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>maxi)
            {
                maxi=nums[i];
                pos=i;
            }
        }
        TreeNode* root=new TreeNode();
        root->val=nums[pos];
        root->left=helper(0,pos-1,nums);
        root->right=helper(pos+1,nums.size()-1,nums);
        return root;
    }
};