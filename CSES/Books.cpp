using namespace std;
#include<bits/stdc++.h>
int main()
{
    int n,target;
    cin>>n>>target;
    int books[n];
    int pages[n];
    for(int i=0;i<n;i++){
        cin>>books[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    int dp[n+1][target+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=target;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=target;j++)
        {
            if(j-books[i-1]>=0)
            {
                dp[i][j]=max(dp[i-1][j],pages[i-1]+dp[i-1][j-books[i-1]]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][target]<<"\n";
}