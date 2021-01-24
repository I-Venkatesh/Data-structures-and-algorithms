using namespace std;
#include <bits/stdc++.h>
int dp[1009][1009];
int lps(string s)
{
    string t=s;
    int i=0,j=s.length()-1;
    while(i<=j)
    {
        swap(s[i],s[j]);
        i++;
        j--;
    }
    for(int i=0;i<=s.length();i++)
    {
        for(int j=0;j<=t.length();j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[s.length()][s.length()];
     
}
int main()
{
    string s;
    cin>>s;
    cout<<lps(s)<<"\n";
}