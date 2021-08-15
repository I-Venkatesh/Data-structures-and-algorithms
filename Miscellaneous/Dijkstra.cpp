class Solution {
    #define pi pair<int,int>
    #define pii pair<int,pi>
    #define fi first
    #define sc second
    public:
        vector<pi>dir={{0,1},{0,-1},{1,0},{-1,0}};
    struct comp
    {
        bool operator()(pii &x,pii &y){
            return x.fi>=y.fi; 
        }
    };
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m));
        priority_queue<pii,vector<pii>,comp>pq;
        int ans;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            int x=pq.top().sc.first;
            int y=pq.top().sc.sc;
            int cost=pq.top().fi;
            pq.pop();
            if(x<0||x==n||y<0||y==m ||vis[x][y]){
                continue;
            }
            if(x==n-1 && y==m-1){
                ans=cost;
                break;
            }
            vis[x][y]=1;
            for(int i=0;i<4;i++){
                pq.push({cost+(i+1!=grid[x][y]),{x+dir[i].fi,y+dir[i].sc}});
            }
                
        }
        return ans;
    }
};