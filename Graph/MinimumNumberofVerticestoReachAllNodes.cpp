class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int in[n+1];
        memset(in,0,sizeof(in));
        map<int,bool> mp;
        for(int i=0;i<edges.size();i++)
        {
            in[edges[i][1]]++;
            mp[edges[i][0]]=true;
            mp[edges[i][1]]=true;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0&&mp[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};