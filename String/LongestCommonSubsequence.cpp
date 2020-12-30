#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	string st1,st2;
    cin>>st1>>st2;
    int dp[1001][1001];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=st1.length();i++)
    {
        for(int j=1;j<=st2.length();j++)
        {
            if(st1[i-1]==st2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[st1.length()][st2.length()];
}