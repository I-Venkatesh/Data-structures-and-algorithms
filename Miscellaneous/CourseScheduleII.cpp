class Solution {
public:
    int visited[2001];
    vector<int> ans;
    vector<int> g[2001];
    int ok;
    int dfs(int n)
    {
        if(visited[n]==2)
        {
            ok=1;
            return 0;
        }
        visited[n]=2;
        for(int i=0;i<g[n].size();i++)
        {
            if(visited[g[n][i]]!=1)
            {
                dfs(g[n][i]);
            }
        }
        visited[n]=1;
        ans.push_back(n);
        return 0;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        for(int i=0;i<pre.size();i++)
        {
            g[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==0)
            {
                dfs(i);
            }
        }
        reverse(ans.begin(),ans.end());
        if(ok)
        {
            vector<int> empty;
            return empty;
        }
        return ans;
    }
};