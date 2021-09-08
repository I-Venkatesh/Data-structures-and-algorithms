#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(int n,int x,int y,vector<string> &arr)
{
    if(x==n-1&&y==n-1)
    {
        return 1;
    }
    if(dp[x][y]!=-1)
    {
        return dp[x][y];
    }
    int right=0,down=0;
    if(y+1<n&&arr[x][y+1]!='*')
    {
        right=solve(n,x,y+1,arr)%1000000007;
    }
    if(x+1<n&&arr[x+1][y]!='*')
    {
        down=solve(n,x+1,y,arr)%1000000007;
    }
    return dp[x][y]=(right+down)%1000000007;
}
int main()
{
    int n;
    cin>>n;
    vector<string> arr;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        string s="";
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            s+=ch;
        }
        arr.push_back(s);
    }
    if(arr[0][0]=='*'||arr[n-1][n-1]=='*')
    {
        cout<<0<<"\n";
    }
    else{
    cout<<solve(n,0,0,arr);
    }
}