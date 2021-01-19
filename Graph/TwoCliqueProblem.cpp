#include<bits/stdc++.h>
using namespace std;
int color[1000005];
bool biparitie(int G[][5],int src)
{
    for(int i=0;i<6;i++)
    {
        color[i]=-1;
    }
    queue<int> q;
    color[src]=1;
    q.push(src);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int v=0;v<5;v++)
        {
            if(G[p][v]&&color[v]==-1)
            {
                color[v]=1-color[p];
                q.push(v);
            }
            else if(G[p][v]&&color[p]==color[v])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
   int g[5][5]={{0, 1, 1, 0, 0},
                  {1, 0, 1, 1, 0},
                  {1, 1, 0, 0, 0},
                  {0, 1, 0, 0, 1},
                  {0, 0, 0, 1, 0}};
                  for(int i=0;i<5;i++)
                  {
                      for(int j=0;j<5;j++)
                      {
                          g[i][j]=(i!=j)?!g[i][j]:0;
                      }
                  }
                  cout<<biparitie(g,0)<<"\n";

}