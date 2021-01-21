using namespace std;
#include<bits/stdc++.h>
int dp[1000][1000];
int lcs(int x, int y, string s1, string s2){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=s1.size();i++)
    {
        for(int j=1;j<=s2.size();j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[s1.size()][s2.size()];
}
int main()
{
    int a=6,b=6;
    string str1="ABCDGH";
    string str2="AEDFHR";
    cout<<lcs(a,b,str1,str2)<<"\n";
}