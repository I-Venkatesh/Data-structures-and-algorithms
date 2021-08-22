class Solution {
public:
    int visited[500005];
    int ans;
    int dfs(vector<pair<int,int>> g[],int curr)
    {
        visited[curr]=1;
        for(auto i:g[curr])
        {
            if(visited[i.first]==0)
            {
                ans+=i.second;
                dfs(g,i.first);
            }
        }
        return ans;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        memset(visited,0,sizeof(visited));
        vector<pair<int,int>> g[500006];
        for(int i=0;i<connections.size();i++)
        {
            int u=connections[i][0];
            int v=connections[i][1];
            g[v].push_back({u,0});
            g[u].push_back({v,1});
        }
        return dfs(g,0);
    }
};