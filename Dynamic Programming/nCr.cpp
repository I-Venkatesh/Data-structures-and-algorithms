using namespace std;
#include <bits/stdc++.h>
int dp[1009][1009];
int nCr(int n,int c)
    {
        if(c>n)
        {
            return dp[n][c]=0;
        }
        if(c==0||n==c)
        {
            return dp[n][c]=1;
        }
        if(dp[n][c]!=-1)
        {
            return dp[n][c];
        }
        int left=nCr(n-1,c-1)%1000000007;
        int right=nCr(n-1,c)%1000000007;
        return dp[n][c]=(left+right)%1000000007;
    }
    int calc(int n, int r){
        // code here
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<r+1;j++)
            {
                dp[i][j]=-1;
            }
        }
        return nCr(n,r);
    }
int main()
{
    int n=3,r=2;
    cout<<calc(n,r);
}