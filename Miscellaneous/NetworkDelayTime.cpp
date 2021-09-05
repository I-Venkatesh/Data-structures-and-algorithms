class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dij(n,INT_MAX);
        dij[k-1]=0;
        vector<vector<pair<int,int>>>graph(n);
        int x=times.size();
        for(int i=0;i<x;i++)
        {
            int a=times[i][0];
            int b=times[i][1];
            int c=times[i][2];
            graph[a-1].push_back({b-1,c});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<bool>vis(n,false);
        q.push({0,k-1});
        while(!q.empty())
        {
            auto it=q.top();
            q.pop();
            int t=it.first;
            int v=it.second;
            vis[v]=true;
            for(auto u:graph[v])
            {
                int node=u.first;
                int d=u.second;
                if(!vis[node]&&dij[node]>d+dij[v])
                {
                    dij[node]=d+dij[v];
                    q.push({dij[node],node});
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            res=max(res,dij[i]);
        }  
        return res==INT_MAX ? -1 : res;
    }
    
};