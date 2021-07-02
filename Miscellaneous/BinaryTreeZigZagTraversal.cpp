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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode* > q;
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        int level=0;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                if(q.front()->left!=NULL)
                {
                    q.push(q.front()->left);
                }
                if(q.front()->right!=NULL)
                {
                    q.push(q.front()->right);
                }
                if(q.front()!=NULL)
                {
                    temp.push_back(q.front()->val);
                }
                if(!q.empty())
                {
                    q.pop();
                }
            }
            if(level&1)
            {
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            else{
                ans.push_back(temp);
            }
            level++;
        }
        return ans;
    }
};