using namespace std;
#include <bits/stdc++.h>
int visited[100][100];
int X[4] = {1, 0, -1, 0};
int Y[4] = {0, 1, 0, -1};
bool valid(int x, int y, int n, int m)
{
    if (x >= 0 && y >= 0 && x < n && y < m && visited[x][y] == 0)
    {
        return true;
    }
    return false;
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int n = image.size();
    int m = image[0].size();
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = 0;
    int temp = image[sr][sc];
    image[sr][sc] = newColor;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for (int i = 0; i < 4; i++)
        {
            if (valid(x + X[i], y + Y[i], n, m) && temp == image[x + X[i]][y + Y[i]])
            {
                visited[x + X[i]][y + Y[i]] = 1;
                image[x + X[i]][y + Y[i]] = newColor;
                q.push({x + X[i], y + Y[i]});
            }
        }
    }
    return image;
}
int main()
{
    vector<vector<int>> arr= {{1, 1, 1},
                             {1, 1, 0},
                             {1, 0, 1}};
    vector<vector<int>> ans=floodFill(arr,1,1,2);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}



