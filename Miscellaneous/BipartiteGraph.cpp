class Solution {
public:
    int color[101]; 
    int checkBipartite(vector<vector<int>>& g,int curr)
    {
        queue<int> q;
        q.push(curr);
        color[curr]=1;
        while(!q.empty())
        {
            int hold=q.front();
            q.pop();
            for(int i=0;i<g[hold].size();i++)
            {
                if(color[hold]==color[g[hold][i]])
                {
                    return false;
                }
                if(color[g[hold][i]]==-1)
                {
                    color[g[hold][i]]=1-color[hold];
                    q.push(g[hold][i]);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        bool ok=true;
        memset(color,-1,sizeof(color));
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            {
                if(!checkBipartite(graph,i))
                {
                    return false;           
                }
            }
        }
        return true;
    }
};