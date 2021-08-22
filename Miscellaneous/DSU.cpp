class Solution {
public:
    int parent[1001];
    int rank[1001];
    int findParent(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    void dsu(int u,int v)
    {   
        u=findParent(u);
        v=findParent(v);
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if(rank[v]<rank[u])
        {
            parent[v]=u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=0;i<=edges.size();i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
        for(auto i:edges)
        {
            if(findParent(i[0])!=findParent(i[1]))
            {
                dsu(i[0],i[1]);
            }
            else{
                return i;
            }
        }
        return {-1,-1};
    }
};