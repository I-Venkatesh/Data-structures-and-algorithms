class Solution {
public:
    int dp[21][2001];
    int calc(vector<int>& nums, int S,int sum,int curr)
    {
        if(sum==S&&curr==nums.size())
        {
            return 1;
        }
        if(curr>=nums.size())
        {
            return 0;
        }
        if(dp[curr][sum+1001]!=INT_MIN)
        {
            return dp[curr][sum+1001];
        }
        return dp[curr][sum+1001]=calc(nums,S,sum+nums[curr],curr+1)+calc(nums,S,sum-nums[curr],curr+1);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        for(int i=0;i<21;i++)
        {
            for(int j=0;j<2000;j++)
            {
                dp[i][j]=INT_MIN;
            }
        }
        return calc(nums,S,0,0);
    }
};