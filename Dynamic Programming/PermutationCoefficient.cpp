using namespace std;
#include <bits/stdc++.h>
int dp[1009][1009];
int nPr(int n,int c)
    {
        if(c>n)
        {
            return dp[n][c]=0;
        }
        if(c==0)
        {
            return dp[n][c]=1;
        }
        if(dp[n][c]!=-1)
        {
            return dp[n][c];
        }
        int left=nPr(n-1,c);
        int right=c*(nPr(n-1,c-1));
        return dp[n][c]=(left+right);
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
        return nPr(n,r);
    }
int main()
{
    int n=10,r=3;
    cout<<calc(n,r);
}