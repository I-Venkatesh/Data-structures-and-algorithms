class Solution {
public:
    vector<int> graph[100005];
    int visited[100005];
    bool cycle(int index)
    {
        if(visited[index]==2)
        {
            return true;
        }
        visited[index]=2;
        for(int i=0;i<graph[index].size();i++)
        {
            if(visited[graph[index][i]]!=1)
            {
                if(cycle(graph[index][i]))
                {
                    return true;
                }
            }
            
        }
        visited[index]=1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==0)
            {
                if(cycle(i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};