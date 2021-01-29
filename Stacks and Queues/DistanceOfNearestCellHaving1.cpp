using namespace std;
#include <bits/stdc++.h>
int X[4]={1,-1,0,0};
    int Y[4]={0,0,1,-1};
    int valid(int i,int j,int n,int m)
    {
        if(i>=0&&i<n&&j>=0&&j<m)
        {
            return 1;
        }
        return 0;
    }
	vector<vector<int>>nearest(vector<vector<int>>grid){
	   int mat[501][501];
	   int n=grid.size();
	   int m=grid[0].size();
	   queue<pair<int,int>> q;
	   for(int i=0;i<n;i++)
	   {
	       for(int j=0;j<m;j++)
	       {
	           if(grid[i][j]==1)
	           {
	               q.push({i,j});
	           }
	           mat[i][j]=INT_MAX;
	       }
	   }
	   int dis=0;
	   while(!q.empty())
	   {
	       int size=q.size();
	       for(int j=0;j<size;j++)
	       {
	           pair<int,int> p=q.front();
    	       q.pop();
    	       int x=p.first;
    	       int y=p.second;
    	       mat[x][y]=min(dis,mat[x][y]);
    	       for(int i=0;i<4;i++)
    	       {
    	           if(valid(x+X[i],y+Y[i],n,m)&&mat[x+X[i]][y+Y[i]]==INT_MAX)
    	           {
    	               q.push({x+X[i],y+Y[i]});
    	           }
    	       }
	       }
	       dis++;
	   }
	   vector<vector<int>>vec(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vec[i][j]=mat[i][j];
            }
        }
	   return vec;
	}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        arr.push_back(temp);
    }
    vector<vector<int>> ans=nearest(arr);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}