using namespace std;
#include<bits/stdc++.h>
int X[4] = {1, -1, 0, 0};
int Y[4] = {0, 0, 1, -1};
int valid(int i, int j, int n, int m)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
    {
        return 1;
    }
    return 0;
}
int bfs(vector<vector<int>> &grid, int rot)
{
    int visited[501][501];
    memset(visited, 0, sizeof(visited));
    int rotten = 0;
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                rotten++;
            }
        }
    }
    int maxi = 1;
    while (!q.empty())
    {
        pair<pair<int, int>, int> curr = q.front();
        q.pop();
        int x = curr.first.first;
        int y = curr.first.second;
        int t = curr.second;
        for (int i = 0; i < 4; i++)
        {
            if (valid(x + X[i], y + Y[i], grid.size(), grid[0].size()))
            {
                if (visited[x + X[i]][y + Y[i]] == 0)
                {
                    visited[x + X[i]][y + Y[i]] = 1;
                    if (grid[x + X[i]][y + Y[i]] == 1)
                    {
                        rotten++;
                        maxi = max(maxi, t + 1);
                        q.push({{x + X[i], y + Y[i]}, t + 1});
                    }
                }
            }
        }
    }
    if (rot == rotten)
    {
        return maxi;
    }
    else
    {
        return INT_MAX;
    }
}
int orangesRotting(vector<vector<int>> &grid)
{
    int mini = INT_MAX, rot = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1 || grid[i][j] == 2)
            {
                rot++;
            }
        }
    }
    mini = min(mini, bfs(grid, rot));
    if (mini == INT_MAX)
    {
        return -1;
    }
    return mini;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++)
    {
        vector<int> temp;
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        arr.push_back(temp);
    }
    cout<<orangesRotting(arr)<<"\n";
}