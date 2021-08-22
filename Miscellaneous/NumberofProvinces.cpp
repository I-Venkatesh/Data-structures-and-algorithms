class Solution {
public:
    int visited[201];
    vector<int> g[10005];
    void dfs(int curr)
    {
        visited[curr]=1;
        for(auto i:g[curr])
        {
            if(visited[i]==0)
            {
                dfs(i);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        memset(visited,0,sizeof(visited));
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                if(isConnected[i][j]==1)
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(visited[i]==0)
            {
                ans++;
                dfs(i);
            }
        }
        return ans;
    }
};