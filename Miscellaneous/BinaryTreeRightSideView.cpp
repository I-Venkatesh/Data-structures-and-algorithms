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
    int visited[105];
    vector<int> ans;
    void dfs(TreeNode* root,int level)
    {
        if(root==NULL)
        {
            return;
        }
        if(visited[level]==-1)
        {
            visited[level]=1;
            ans.push_back(root->val);
        }
        dfs(root->right,level+1);
        dfs(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        memset(visited,-1,sizeof(visited));
        dfs(root,0);
        return ans;
    }
};