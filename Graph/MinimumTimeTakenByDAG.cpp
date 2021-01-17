using namespace std;
#include<bits/stdc++.h>
vector<int> graph[100005];
int inDegree[100005];
int job[100005];
void addEdge(int x,int y)
{
    graph[x].push_back(y);
    inDegree[y]++;
}
void topologicalSort(int n,int m)
{
    queue<int> q;
    for(int i=0;i<=n;i++)
    {
        if(inDegree[i]==0)
        {
            q.push(i);
            job[i]=1;
        }
    }
    while(!q.empty())
    {
        int curr=q.front();
        // cout<<curr<<"\n";
        q.pop();
        for(auto i:graph[curr])
        {
            inDegree[i]--;
            if(job[i]<1+job[curr])
            {
                job[i]=max(job[i],1+job[curr]);
            }
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        cout<<job[i]<<" ";
    }
}
int dfs(int i,int visited[],stack<int> &st)
{
    visited[i]=true;
    for(auto j:graph[i])
    {
        if(!visited[j])
        {
            dfs(j,visited,st);
        }
    }
    st.push(i);
}
void topologicalUsingStack(int n,int m)
{
    stack<int> st;
    int visited[100005];
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited, st);
        }
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
}
int main()
{
    int n=10,m=13;
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);
    topologicalSort(n,m);
    topologicalSort(n,m);
}