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
    map<pair<TreeNode*,int>,int> mp;
    int dfs(TreeNode* root,int temp)
    {
        if(root==NULL)
        {
            return 0;
        }
        if(mp[{root,temp}]!=0)
        {
            return mp[{root,temp}];
        }
        int add1=0,add2=0,add3=0;
        if(temp==0)
        {
            add1=root->val+dfs(root->left,1)+dfs(root->right,1);
        }
        if(temp==1)
        {
            add2=dfs(root->left,0)+dfs(root->right,0);
        }
        add3=dfs(root->left,temp)+dfs(root->right,temp);
        return mp[{root,temp}]=max(max(add1,add3),add2);
    }
    int rob(TreeNode* root) {
        return dfs(root,0);
    }
};