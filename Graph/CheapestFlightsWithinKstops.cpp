#include<bits/stdc++.h>
using namespace std;
int visited[100005];
void dfs(vector<pair<int, int>> graph[], int s, int &fare, int totcost, int k, int dest)
{
    if (k < -1 || totcost > fare)
    {
        return;
    }
    if (s == dest)
    {
        fare = min(fare, totcost);
        return;
    }
    visited[s] = 1;
    for (auto &i : graph[s])
    {
        if (!visited[i.first])
        {
            dfs(graph, i.first, fare, totcost + i.second, k - 1, dest);
        }
    }
    visited[s] = 0;
}
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    vector<pair<int, int>> graph[100005];
    int INF = 20000000;
    for (int i = 0; i < flights.size(); i++)
    {
        int u = flights[i][0];
        int v = flights[i][1];
        int w = flights[i][2];
        graph[u].push_back({v, w});
    }
    int fare = INF;
    dfs(graph, src, fare, 0, K, dst);
    if (fare == INF)
    {
        return -1;
    }
    return fare;
}
int main()
{
    vector<vector<int>> flights={{0,1,100},{1,2,100},{0,2,500}};
    int src=0,dest=2,k=1;
    cout<<findCheapestPrice(3,flights,src,dest,k);
}