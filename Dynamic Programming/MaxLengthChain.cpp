using namespace std;
#include<bits/stdc++.h>
int maxChainLen(vector<pair<int,int>> p,int n)
{
    int dp[100000];
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
    }
    sort(p.begin(),p.end());
    for(int i=0;i<n;i++)
    {
        int maxi=0;
        for(int j=0;j<n;j++)
        {
            if(p[j].second<p[i].first)
            {
                maxi=max(dp[j],maxi);
            }
        }
        dp[i]=maxi+1;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,dp[i]);
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    cout<<maxChainLen(v,n)<<"\n";
}