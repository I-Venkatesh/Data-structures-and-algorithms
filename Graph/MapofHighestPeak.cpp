class Solution {
public:
    int X[4]={1,0,-1,0};
    int Y[4]={0,1,0,-1};
    int S=1001;
    int visited[1001][1001];
    int valid(int i,int j,int m,int n)
    {
        if(i<0||i>=n||j<0||j>=m)
        {
            return 0;
        }
        return 1;
    }

     vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> isWaters(n , vector<int> (m, -1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1)
                {
                    q.push({i,j});
                    isWaters[i][j]=0;
                }
            }
        }
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            int x1=p.first;
            int y1=p.second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(valid(x1+X[i],y1+Y[i],m,n)&&isWaters[x1+X[i]][y1+Y[i]]==-1)
                {
                    isWaters[x1+X[i]][y1+Y[i]]=1+isWaters[x1][y1];
                    q.push({x1+X[i],y1+Y[i]});
                }
            }
        }

        return isWaters;
    }
};