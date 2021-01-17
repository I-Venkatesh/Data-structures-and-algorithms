using namespace std;
#include <bits/stdc++.h>
int X[8] = {1, 0, 1, -1, 0, -1, -1, 1};
int Y[8] = {0, 1, 1, -1, -1, 0, 1, -1};
int valid(int n, int m, int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    return false;
}
int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int visited[n + 1][m + 1];
    int count = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {
                count++;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty())
                {
                    pair<int, int> p = q.front();
                    int x = p.first;
                    int y = p.second;
                    q.pop();
                    for (int i = 0; i < 8; i++)
                    {
                        if (valid(n, m, x + X[i], y + Y[i]) && visited[x + X[i]][y + Y[i]] == 0 && grid[x + X[i]][y + Y[i]] == '1')
                        {
                            visited[x + X[i]][y + Y[i]] = 1;
                            q.push({x + X[i], y + Y[i]});
                        }
                    }
                }
            }
        }
    }
    return count;
}
int main()
{
    vector<vector<char>> grid={{'0','1'},{'1','0'},{'1','1'},{'1','0'}};
    cout<<numIslands(grid);

}