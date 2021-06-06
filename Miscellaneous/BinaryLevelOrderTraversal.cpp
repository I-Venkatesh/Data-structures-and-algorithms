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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> t;
        t.push_back(root->val);
        ans.push_back(t);
        while(!q.empty())
        {
            int n=q.size();
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                auto hold=q.front();
                q.pop();
                if(hold->left)
                {
                    temp.push_back(hold->left->val);
                    q.push(hold->left);
                }
                if(hold->right)
                {
                    temp.push_back(hold->right->val);
                    q.push(hold->right);
                }
            }
            if(temp.size()>0)
            {
                ans.push_back(temp);
            }
            temp.clear();
        }
        return ans;
    }
};