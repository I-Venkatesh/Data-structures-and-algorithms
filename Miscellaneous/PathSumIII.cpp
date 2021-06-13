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
    int ans=0;
    int calc(TreeNode* root, int sumSoFar,int s)
    {
        if(root==NULL)
        {
            return 0;
        }
        sumSoFar+=root->val;
        return (sumSoFar==s)+calc(root->left,sumSoFar,s)+calc(root->right,sumSoFar,s);
       
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        return calc(root,0,targetSum)+pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
    }
};