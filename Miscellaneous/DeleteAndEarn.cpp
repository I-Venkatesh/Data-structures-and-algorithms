class Solution {
public:
    int dp[100005];
    int solve(int curr,int* freq)
    {
        if(curr>=100005)
        {
            return 0;
        }
        if(dp[curr]!=-1)
        {
            return dp[curr];
        }
        return dp[curr]=max(freq[curr]*curr+solve(curr+2,freq),solve(curr+1,freq));
    }
    int deleteAndEarn(vector<int>& nums) {
        int freq[100005];
        memset(dp,-1,sizeof(dp));
        memset(freq,0,sizeof(freq));
        for(int i=0;i<nums.size();i++)
        {
            freq[nums[i]]++;
        }
        return solve(0,freq);
    }
};