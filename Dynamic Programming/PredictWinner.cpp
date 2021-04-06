class Solution {
public:
    int dp[21][21];
    int calc(vector<int>& nums,int l,int r)
    {
        if(l>r)
        {
            return 0;
        }
        if(l+1==r)
        {
            return max(nums[l],nums[r]);
        }
        if(l==r)
        {
            return nums[l];
        }
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        return dp[l][r]=max(nums[l]+min(calc(nums,l+2,r),calc(nums,l+1,r-1)),nums[r]+min(calc(nums,l+1,r-1),calc(nums,l,r-2)));
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        if(nums.size()==1)
        {
            return 1;
        }
        int totSum=0;
        for(auto i:nums)
        {
            totSum+=i;
        }
        int firstMax=calc(nums,0,nums.size()-1);
        int secondMax=totSum-firstMax;
        return (firstMax>=secondMax);
    }
};