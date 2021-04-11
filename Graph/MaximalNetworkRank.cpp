class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if(roads.size()==0)
        {
            return 0;
        }
        int arr[101];
        memset(arr,0,sizeof(arr));
        int graph[101][101];
        memset(graph,0,sizeof(graph));
        for(int i=0;i<roads.size();i++)
        {
            int x=roads[i][0];
            int y=roads[i][1];
            graph[x][y]=1;
            arr[x]++;
            arr[y]++;
        }
        vector<pair<int,int>> c;
        int ans=0,maxi=0;
        for(int i=0;i<101;i++)
        {
            for(int j=i+1;j<101;j++)
            {
                    ans=arr[i]+arr[j];
                    if(graph[i][j]==1||graph[j][i]==1)
                    {
                        ans--;
                    }
                    maxi=max(maxi,ans);
            }
        }
        return maxi;
        
    }
};