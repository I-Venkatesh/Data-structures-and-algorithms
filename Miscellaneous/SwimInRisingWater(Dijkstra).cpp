typedef pair<int,pair<int,int>> ppi;
class comp{
    public:
    bool operator()(ppi a,ppi b){
        return a.first>b.first;
    }
};
class Solution {
public:
    int X[4]={1,0,-1,0};
    int Y[4]={0,1,0,-1};
    int swimInWater(vector<vector<int>>& grid) 
    {
        int ans=INT_MIN;
        priority_queue<ppi,vector<ppi>,comp> pq;
        int m=grid.size();
		int n=grid[0].size();
	    int visited[m][n];
	    memset(visited,0,sizeof(visited));
        pq.push({grid[0][0],{0,0}});
        while(!pq.empty())
        {
            ans=max(ans,pq.top().first);
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==m-1&&y==n-1)
            {
                break;
            }
            for(int i=0;i<4;i++)
            {
                if(X[i]+x>=0&&X[i]+x<m&&Y[i]+y>=0&&Y[i]+y<n&&visited[X[i]+x][Y[i]+y]==0)
                {
                    visited[X[i]+x][Y[i]+y]=1;
                    pq.push({grid[X[i]+x][Y[i]+y],{X[i]+x,Y[i]+y}});
                }
            }
        }
        return ans;
    }
};