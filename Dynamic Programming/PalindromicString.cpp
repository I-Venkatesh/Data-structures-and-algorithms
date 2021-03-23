class Solution {
public:
    int dp[1001][1001];
    int calc(string s,int i,int j)
    {
        int ans=0;
        if(i>=j)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            ans=calc(s,i+1,j-1);
        }
        return dp[i][j]=ans;
    }
    int countSubstrings(string s) 
    {
        int cnt=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                if(calc(s,i,j))
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};