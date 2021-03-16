class TrieNode{
public:
    TrieNode* left;
    TrieNode* right;
};
TrieNode* root=new TrieNode();
class Solution {
public:
    void insert(int num)
    {
        TrieNode* curr=root;
        for(int i=31;i>=0;i--)
        {
            int b=(num>>i)&1;
            if(b)
            {
                if(!curr->right)
                {
                    curr->right=new TrieNode();
                }
                curr=curr->right;
            }
            else{
                if(!curr->left)
                {
                    curr->left=new TrieNode();
                }
                curr=curr->left;
            }
        }
    }
    int XorMax(int n)
    {
        int curr=0,i=0;
        TrieNode* hold=root;
        for(int i=31;i>=0;i--)
        {
            int b=(n>>i)&1;
            if(b)
            {
                if(hold->left)
                {
                    curr+=pow(2,i);
                    hold=hold->left;
                }
                else{
                    hold=hold->right;
                }
            }
            else
            {
                if(hold->right)
                {
                    curr+=pow(2,i);
                    hold=hold->right;
                }
                else{
                    hold=hold->left;
                }
            }
        }
        return curr;
    }
    int findMaximumXOR(vector<int>& nums) {
        int ans=INT_MIN;
        root->left=NULL;
        root->right=NULL;
        for(int i=0;i<nums.size();i++)
        {
            insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,XorMax(nums[i]));
        }
        return ans;
    }
};