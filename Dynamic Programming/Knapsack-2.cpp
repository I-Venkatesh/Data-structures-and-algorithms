using namespace std;
#include<bits/stdc++.h>
const int MAXV = 1e5 + 10;
const int MAXN = 1e3 + 10;
typedef long long int ll;
const ll INF = 1e13;
int main(){
    ll N,W;
    cin>>N>>W;
    ll V=0;
    ll wt[MAXN],val[MAXN];
    for(int i=1;i<=N;i++)
    {
        cin>>wt[i]>>val[i];
        V+=val[i];
    }
    ll dp[MAXV];
    for(int i=0;i<=V;i++)
    {
        dp[i]=INF;
    }
    dp[0]=0;
    for(int i=1;i<=N;i++)
    {
        int w=wt[i],v=val[i];
        for(int j=V;j>=v;j--)
        {
            dp[j]=min(dp[j],dp[j-v]+w);
        }
    }
    for(int i=V;i>=0;i--)
    {
        if(dp[i]<=W)
        {
            cout<<i<<"\n";
            break;
        }
    }
}