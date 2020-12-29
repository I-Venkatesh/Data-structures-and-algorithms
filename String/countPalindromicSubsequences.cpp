using namespace std;
#include <bits/stdc++.h>
int dp[1000][1000];
int countPS(int i,int j,string str)
{
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(i==j)
    {
        return dp[i][j]=1;
    }
    else if(str[i]==str[j])
    {
        return dp[i][j]=countPS(i+1,j,str)+countPS(i,j-1,str)+1;
    }
    else{
        return dp[i][j]=countPS(i+1,j,str)+countPS(i,j-1,str)-countPS(i+1,j-1,str);
    }
}
int lps(string s)
{
    int n = s.length();
    return countPS(0,n-1,s);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    string s;
    cin >> s;
    cout << lps(s) << "\n";
}