class Solution {
public:
    int dp[60];
    int calc(int n)
    {
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return 1;
        }
         if(n==2)
        {
            return 1;
        }
         if(n==3)
        {
            return 2;
        }
        int maxi=INT_MIN;
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        for(int i=1;i<n;i++)
        {
            maxi=max(i*(n-i),max(maxi,i*calc(n-i)));
        }
        return dp[n]=maxi;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        int maxi=calc(n);
        return maxi;
    }
};