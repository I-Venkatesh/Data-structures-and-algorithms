/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int visitedP,visitedQ,levelP=0,levelQ=0;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
        {
            return root;
        }
        if(p==root||q==root)
        {
            return root;
        }
        TreeNode* left=lowestCommonAncestor(root->left, p, q);
        TreeNode* right=lowestCommonAncestor(root->right, p, q);
        if(left&&right)
        {
            return root;
        }
        if(left)
        {
            return left;
        }
        if(right)
        {
            return right;
        }
        return NULL;
    }
};