class Solution {
public:
    vector<TreeNode*> ans;
    TreeNode* rem(TreeNode* root, vector<int>& del)
    {
        if(root==NULL)
        {
            return NULL;
        }
        root->left=rem(root->left,del);
        root->right=rem(root->right,del);
        for(int i=0;i<del.size();i++)
        {
            if(root->val==del[i])
            {
                if(root->left)
                {
                    ans.push_back(root->left);
                }
                if(root->right)
                {
                    ans.push_back(root->right);
                }
                return NULL;
            }
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        root=rem(root,to_delete);
        if(root)
        ans.push_back(root);
        return ans;
    }
};