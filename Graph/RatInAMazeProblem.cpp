using namespace std;
#include <bits/stdc++.h>
vector<string> ans;
int X[4] = {-1, 0, 0, 1};
int Y[4] = {0, -1, 1, 0};
string directions;
int visited[1000][1000];
bool valid(int m[4][4], int x, int y, int n)
{
    if (x < n && x >= 0 && y < n && y >= 0 && m[x][y] == 1&&visited[x][y]==0)
    {
        return true;
    }
    return false;
}
void maze(int m[4][4], int x, int y, int n)
{
    if (x == n - 1 && y == n - 1 )
    {
        for (auto i : directions)
        {
            cout << i;
        }
        cout<<"\n";
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        
        if (valid(m, x + X[i], y + Y[i], n))
        {
            visited[x][y] = 1;
            if (i == 0)
            {
                directions.push_back('U');
                maze(m, x + X[i], y + Y[i], n);
                directions.pop_back();
            }
            if (i == 1)
            {
                directions.push_back('L');
                maze(m, x + X[i], y + Y[i], n);
                directions.pop_back();
            }
            if (i == 2)
            {
                directions.push_back('R');
                maze(m, x + X[i], y + Y[i], n);
                directions.pop_back();
            }
            if (i == 3)
            {
                directions.push_back('D');
                maze(m, x + X[i], y + Y[i], n);
                directions.pop_back();
            }
            visited[x][y] = 0;
        }
    }
}
void findPath(int m[][4], int n)
{
    // Your code goes here
    memset(visited, 0, sizeof(visited));
    maze(m, 0, 0, n);
}
int main()
{
    int arr[4][4] = {{1, 0, 0, 0},
                     {1, 1, 0, 1},
                     {1, 1, 0, 0},
                     {0, 1, 1, 1}};
    findPath(arr, 4);
}
