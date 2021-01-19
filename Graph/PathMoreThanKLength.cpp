#include<bits/stdc++.h>
using namespace std;
int visited[100005];
bool ok;
vector<pair<int,int>> graph[1000];
bool dfs(int src,int k,int sum)
{
    if(sum>=k)
    {
        return true;
    }
    visited[src]=1;
    for(auto i:graph[src])
    {
        if(!visited[i.first])
        {
            if(dfs(i.first,k,sum+i.second)){
                return true;
            }
        }
    }
    visited[src]=0;
    return false;
}
int main()
{
    int V=9;
    graph[0].push_back({1,4});
    graph[0].push_back({7,8});
    graph[1].push_back({2,8});
    graph[1].push_back({7,11});
    graph[2].push_back({3,7});
    graph[2].push_back({8,2});
    graph[2].push_back({5,4});
    graph[3].push_back({4,9});
    graph[3].push_back({5,14});
    graph[4].push_back({5,10});
    graph[5].push_back({6,2});
    graph[6].push_back({7,1});
    graph[6].push_back({8,6});
    graph[7].push_back({8,7});

    graph[1].push_back({0,4});
    graph[7].push_back({0,8});
    graph[2].push_back({1,8});
    graph[7].push_back({1,11});
    graph[3].push_back({2,7});
    graph[8].push_back({2,2});
    graph[5].push_back({2,4});
    graph[4].push_back({3,9});
    graph[5].push_back({3,14});
    graph[5].push_back({4,10});
    graph[6].push_back({5,2});
    graph[7].push_back({6,1});
    graph[8].push_back({6,6});
    graph[8].push_back({7,7});
    int src=0,k=60;
    memset(visited,0,sizeof(visited));
    int sum=0;
    bool ans=dfs(src,k,sum);
    if(ans)
    {
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n"; 
    }
}