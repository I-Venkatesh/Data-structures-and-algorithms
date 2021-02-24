using namespace std;
#include<bits/stdc++.h>
string s,t;
int main(){
    
    cin>>s>>t;
    int dp[s.length()+1][t.length()+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=s.length();i++)
    {
        for(int j=0;j<=t.length();j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else{
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    for(int i=0;i<=s.length();i++)
    {
        for(int j=0;j<=t.length();j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    int c=1;
    string ans;
    int i=s.length(),j=t.length();
    while(i>0&&j>0)
    {
        if(dp[i-1][j]==dp[i][j])
        {
            i--;
        }
        else if(dp[i][j-1]==dp[i][j])
        {
            j--;
        }
        else{
            ans.push_back(t[j-1]);
            i--;
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";

}