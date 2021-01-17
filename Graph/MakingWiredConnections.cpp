using namespace std;
#include <bits/stdc++.h>
int visited[100005];
vector<int> g[100005];
void dfs(int parent, int child)
{
    visited[parent] = 1;
    // cout<<parent<<" ";
    for (int i = 0; i < g[parent].size(); i++)
    {
        if (g[parent][i] != parent)
        {
            if (!visited[g[parent][i]])
            {
                dfs(child, g[parent][i]);
            }
        }
    }
    return;
}
int makeConnected(int n, vector<vector<int>> &connections)
{
    if (connections.size() < n - 1)
    {
        return -1;
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < connections.size(); i++)
    {
        g[connections[i][0]].push_back(connections[i][1]);
        g[connections[i][1]].push_back(connections[i][0]);
    }
    dfs(0, 0);
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (visited[i] == 0)
        {
            count++;
            dfs(i, i);
        }
    }

    return count;
}
int main()
{
    vector<vector<int>> arr = {{0, 1},
                               {0, 2},
                               {1, 2}};
    cout<<makeConnected(4,arr)<<"\n";
}
