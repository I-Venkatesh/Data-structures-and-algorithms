using namespace std;
#include<bits/stdc++.h>
int X[4]={-1,0,0,1};
int Y[4]={0,-1,1,0};
string directions;
vector<string> ans;
int MAXN=100;
int visited[1000][1000];
int arr[100][100];
bool valid(int x,int y,int n)
{
       if (x < n && x >= 0 && y < n && y >= 0 && arr[x][y] == 1&&visited[x][y]==0)
    {
        return true;
    }
    return false;
}

void maze(int x,int y,int n)
{
    if(x==-1||y==-1||x==n||y==n||visited[x][y]==1||arr[x][y]==0)
    {
        return;
    }
    if (x == n - 1 && y == n - 1 )
    {
        ans.push_back(directions);
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        
        if (valid( x + X[i], y + Y[i], n))
        {
            visited[x][y] = 1;
            if (i == 0)
            {
                directions.push_back('U');
                maze( x + X[i], y + Y[i], n);
                directions.pop_back();
            }
            if (i == 1)
            {
                directions.push_back('L');
                maze( x + X[i], y + Y[i], n);
                directions.pop_back();
            }
            if (i == 2)
            {
                directions.push_back('R');
                maze( x + X[i], y + Y[i], n);
                directions.pop_back();
            }
            if (i == 3)
            {
                directions.push_back('D');
                maze( x + X[i], y + Y[i], n);
                directions.pop_back();
            }
            visited[x][y] = 0;
        }
    }
    return;
}
vector<string> findPath(int n) {
    // Your code goes here
    memset(visited,0,sizeof(visited));
    directions.clear();
    set<string> s;
    ans.clear();
    s.clear();
    maze(0,0,n);
    for(auto i:ans)
    {
        s.insert(i);
    }
    ans.clear();
    for(auto i:s)
    {
        ans.push_back(i);
    }
    return ans;
}
int main()
{
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            cin>>arr[i][j];
        }
    }
    findPath(num);
    for(auto i:ans)
    {
        cout<<i<<"\n";
    }
}