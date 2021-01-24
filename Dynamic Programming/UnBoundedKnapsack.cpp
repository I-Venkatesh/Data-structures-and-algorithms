using namespace std;
#include <bits/stdc++.h>
int dp[1009][1009];
int unBoundedknapSack(int N, int W, int val[], int wt[])
    {
        int dp[N+1][W+1];
        for(int i=0;i<=N;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=W;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(j>=wt[i-1])
                {
                    dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[N][W];
    }

int main()
{
    int n=2,W=3;
    int val[3]={1,1};
    int wt[3]={2,1};
    cout << unBoundedknapSack(n,W,val,wt)<<"\n";
}