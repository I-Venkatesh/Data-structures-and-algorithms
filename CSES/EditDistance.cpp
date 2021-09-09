using namespace std;
#include<bits/stdc++.h>
int main()
{   
    string s,t;
    cin>>s>>t;
    int dp[s.length()+1][t.length()+1];
    for(int i=0;i<=s.length();i++)
    {
        dp[i][0]=i;
    }
    for(int i=0;i<=t.length();i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=s.length();i++)
    {
        for(int j=1;j<=t.length();j++)
        {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
        }
    }
    cout<<dp[s.length()][t.length()]<<"\n";
}