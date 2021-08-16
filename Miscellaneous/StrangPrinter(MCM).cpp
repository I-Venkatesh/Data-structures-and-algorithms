class Solution {
public:
    int dp[101][101];
    int solve(string s,int i,int j)
    {
        if(i>j)
        {
            return 0;
        }
        if(i==j)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=INT_MAX;
        ans=min(ans,1+solve(s,i+1,j));
        for(int k=i+1;k<=j;k++)
        {
            if(s[i]==s[k])
            {
                 ans=min(ans,solve(s,i,k-1)+solve(s,k+1,j));   
            }
        }
        return dp[i][j]=ans;
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,s.length()-1);
    }
};