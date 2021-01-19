using namespace std;
#include <bits/stdc++.h>
int dp[1009][1009];
int knapSack(int W, int wt[], int val[], int n) 
{ 
   // Your code her
   for(int i=0;i<=W+1;i++)
   {
       dp[0][i]=0;
   }
   for(int i=0;i<=n+1;i++)
   {
       dp[i][0]=0;
   }
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=W;j++)
       {
           if(j-wt[i-1]>=0)
           {
                dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
           }
           else
           {
               dp[i][j]=dp[i-1][j];
           }
       }
   }
   return dp[n][W];
}


int main()
{
    int n=3,W=4;
    int val[3]={1,2,3};
    int wt[3]={4,5,1};
    cout << knapSack(W,wt,val,n);
}