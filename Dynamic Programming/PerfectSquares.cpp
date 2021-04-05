class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=100001;
        }
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sqrt(n);j++)
            {
                if(i-(j*j)>=0)
                {
                    dp[i]=min(dp[i],1+dp[i-(j*j)]);
                }
                else{
                    break;
                }
            }      
        }
        return dp[n];
    }
};