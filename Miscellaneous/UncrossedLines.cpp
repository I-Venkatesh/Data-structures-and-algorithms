class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2,int x,int y)
    {
        if(x==nums1.size()||y==nums2.size())
        {
            return 0;
        }
        if(dp[x][y]!=-1)
        {
            return dp[x][y];
        }
        int ans=0;
        if(nums1[x]==nums2[y])
        {
            ans=1+solve(nums1,nums2,x+1,y+1);
        }
        else
        {
            ans=max(solve(nums1,nums2,x+1,y),solve(nums1,nums2,x,y+1));
        }
        return dp[x][y]=ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,0,0);
    }
};