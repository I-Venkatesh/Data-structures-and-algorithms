class Solution
{
public:
    int dp[1001][1001];
    map<string,bool> mp;
    bool wb(string A,vector<string> &B,int i,int j)
    {
        if(find(B.begin(),B.end(),A.substr(i,j-i+1))!=B.end())
        {
            return 1;
        }
        if(i==j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        for(int k=i;k<j;k++)
        {
            if(wb(A,B,i,k)&&wb(A,B,k+1,j))
            {
                return dp[i][j]=1;
            }
        }
        return dp[i][j]=0;
    }
    int wordBreak(string A, vector<string> &B) {
        memset(dp,-1,sizeof(dp));
        return wb(A,B,0,A.size()-1);
    }
};