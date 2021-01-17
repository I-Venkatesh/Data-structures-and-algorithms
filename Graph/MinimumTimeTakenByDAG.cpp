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
}