class Solution {
public:
    int dp[400005][3];
    int calc(vector<int>& nums,int curr,int r)
    {
        if(curr==nums.size())
        {
            return r%3?INT_MIN:0;
        }
        if(dp[curr][r]!=-1)
        {
            return dp[curr][r];
        }
        return dp[curr][r]=max(nums[curr]+calc(nums,curr+1,(r+nums[curr])%3),calc(nums,curr+1,r));
    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return calc(nums,0,0);
    }
};