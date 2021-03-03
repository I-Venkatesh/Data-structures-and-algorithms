using namespace std;
#include<bits/stdc++.h>
int n,m;
char arr[1001][1001];
int dp[1001][1001];
int valid(int i,int j)
{
    if(i<n&&j<m&&i>=0&&j>=0&&arr[i][j]=='.')
    {
        return 1;
    }
    return 0;
}
int recur(int i,int j){
    if(i==n-1&&j==m-1)
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int down=0,right=0;
    if(valid(i+1,j)==1)
    {
        down=recur(i+1,j);
    }
    if(valid(i,j+1)==1)
    {
        right=recur(i,j+1);
    }
    return dp[i][j]=(down+right)%1000000007;
}
int main(){
     cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<recur(0,0);
}