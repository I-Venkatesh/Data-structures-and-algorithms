using namespace std;
#include <bits/stdc++.h>
int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{
    // Code here
    int dist[n + 1];
    int MAXN = 100005;
    for (int i = 0; i < n; i++)
    {
        dist[i] = MAXN;
    }
    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if (dist[u] != MAXN && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int j = 0; j < edges.size(); j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if (dist[u] != MAXN && dist[u] + w < dist[v])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    vector<vector<int>> grid = {{0,1,-1},{1,2,-2},{2,0,-3}};
    int n=3;
    cout << isNegativeWeightCycle(n,grid);
}