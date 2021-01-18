#include<bits/stdc++.h>
using namespace std;
int visited[100006];
vector<int> rev[100005];
void dfs(int num, vector<int> adj[], stack<int> &st)
{
    visited[num] = 1;
    for (auto i : adj[num])
    {
        if (!visited[i])
        {
            dfs(i, adj, st);
        }
    }
    st.push(num);
}
void dfs2(int num)
{
    visited[num] = 1;
    for (auto i : rev[num])
    {
        if (!visited[i])
        {
            dfs2(i);
        }
    }
}
void reverse(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            rev[j].push_back(i);
        }
    }
}
int kosaraju(int V, vector<int> adj[])
{
    //code here
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        rev[i].clear();
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, st);
        }
    }
    memset(visited, 0, sizeof(visited));
    reverse(adj, V);
    int count = 0;
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        if (!visited[curr])
        {
            dfs2(curr);
            count++;
        }
    }
    return count;
}
int main()
{
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    cout<<kosaraju(V,adj);
}