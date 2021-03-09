class Solution {
public:
    int dp[51][51];
    int countVowelStrings(int n) {
        for(int i=1;i<=5;i++)
        {
            dp[1][i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            dp[i][5]=1;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=4;j>=1;j--)
            {
                dp[i][j]=dp[i][j+1]+dp[i-1][j];
            }
        }
        int sum=0;
        for(int i=1;i<=5;i++)
        {
            sum+=dp[n][i];
        }
        return sum;
    }
};