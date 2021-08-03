class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[500][500];
    int helper(int n, int k) 
    {
        if(k==0||k==1)
        {
            return k;
        }
        if(n==1)
        {
            return k;
        }
        if(dp[n][k]!=-1)
        {
            return dp[n][k];
        }
        int mini=INT_MAX;
        for(int i=1;i<=k;i++)
        {
            int t=1+max(helper(n-1,i-1),helper(n,k-i));
            mini=min(mini,t);
        }
        return dp[n][k]=mini;
        // your code here
    }
    int eggDrop(int n, int k) 
    {
       memset(dp,-1,sizeof(dp));
       return helper(n,k);
    }
};