class Solution {
public:
    bool visited[1001];
    void dfs(vector<vector<int>>& rooms,int curr)
    {
        visited[curr]=1;
        for(auto i:rooms[curr])
        {
            if(!visited[i])
            {
                dfs(rooms,i);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int r=rooms.size()-1;
        dfs(rooms,0);
        bool ok=true;
        for(int i=0;i<=r;i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }
        return true;
    }
};