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
    vector<int> left;
    vector<int> right;
    void leftFill(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        leftFill(root->left);
        leftFill(root->right);
        if(root->left)
        {
            left.push_back(root->left->val);
        }
        else{
            left.push_back(-1);
        }
        if(root->right)
        {
            left.push_back(root->right->val);
        }
        else{
            left.push_back(-1);
        }
    }
    void rightFill(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        rightFill(root->right);
        rightFill(root->left);
        if(root->right)
        {
            right.push_back(root->right->val);
        }
        else{
            right.push_back(-1);
        }
        if(root->left)
        {
            right.push_back(root->left->val);
        }
        else{
            right.push_back(-1);
        }
    }
    bool mirror(TreeNode* t1,TreeNode* t2)
    {
        if(t1==NULL&&t2==NULL)
        {
            return true;
        }
        if(t1==NULL||t2==NULL)
        {
            return false;
        }
        return (t1->val==t2->val)&&mirror(t1->left,t2->right)&&mirror(t1->right,t2->left);
    }
    bool isSymmetric(TreeNode* root) {
        // leftFill(root);
        // rightFill(root);
        // for(int i=0;i<left.size();i++)
        // {
        //     if(left[i]!=right[i])
        //     {
        //         return false;
        //     }
        // }
        return mirror(root,root);
    }
};