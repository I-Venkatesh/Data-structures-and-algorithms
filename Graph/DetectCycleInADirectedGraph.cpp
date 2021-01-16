using namespace std;
#include <bits/stdc++.h>
int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> graph[100005];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    vector<int> ans;
    int visited[100005];
    memset(visited, 0, sizeof(visited));
    stack<int> st;
    st.push(0);
    bool ok=true;
    while (!st.empty())
    {
        int x = st.top();
        if (!visited[x])
        {
            ans.push_back(x);
            visited[x] = 1;
        }
        else{
            ok=false;
            cout<<"Loop Found"<<"\n";
            break;
        }
        st.pop();
        for (int i = 0; i < graph[x].size(); i++)
        {
            if (!visited[graph[x][i]])
            {
                st.push(graph[x][i]);
            }
            else{
                ok=false;
            cout<<"Loop Found"<<"\n";
            break;
            }
        }
    }
    if(ok)
    {
        cout<<"No Loop found"<<"\n";
    }
    
}