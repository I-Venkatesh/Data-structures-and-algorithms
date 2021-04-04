using namespace std;
#include<bits/stdc++.h>
long long int arr[1000005];
long long int n,s;
int main()
{
    cin>>n>>s;
    int dp[n+1][s+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s;j++)
        {
            if(i==0||j==0)
            {
                if(i==0)
                {
                    dp[i][j]=0;
                }
                if(j==0)
                {
                    dp[i][j]=1;
                }   
            }
            else if(j-arr[i-1]>=0)
            {
                dp[i][j]=(dp[i-1][j]+dp[i][j-arr[i-1]])%1000000007;
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][s]<<"\n";
}