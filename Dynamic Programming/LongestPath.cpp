using namespace std;
#include<bits/stdc++.h>
int n,m;
vector<int> graph[100005];
bool visited[100005];
int ans;
int dp[100005];
int dfs(int parent)
{
    if(dp[parent]!=-1)
    {
        return dp[parent];
    }
    int maxi=0;
    if(graph[parent].size()==0)
    {
        return dp[parent]=0;
    }
    for(auto i:graph[parent])
    {
        maxi=max(maxi,dfs(i)+1);
    }
    return dp[parent]=maxi;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dfs(i));
    }
    cout<<ans<<"\n";
}