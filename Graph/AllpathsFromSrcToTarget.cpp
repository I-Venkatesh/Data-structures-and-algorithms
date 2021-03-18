class Solution {
public:
    bool visited[100005];
    vector<vector<int>> res;
    vector<int> ans;
    void dfs(int curr,vector<vector<int>>& graph)
    {
        ans.push_back(curr);
        visited[curr]=1;
       if(curr==graph.size()-1)
        {
            return res.push_back(ans);
        }
        if(graph[curr].size()==0&&curr==graph.size()-1)
        {
            return res.push_back(ans);
        }
        for(auto i:graph[curr])
        {
            if(!visited[i])
            {
                dfs(i,graph);
                visited[i]=0;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0,graph);
        return res;
    }
};