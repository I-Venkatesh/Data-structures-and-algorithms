#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define pb push_back

vector<int> graph[100005];
int dfs(int num,vector<bool> &visited)
{
    stack<int> st;
    st.push(num);
    int c=0;
    while(!st.empty())
    {
        int curr=st.top();
        st.pop();
        if(!visited[curr])
        {
            c++;
            visited[curr]=1;
            for(auto i:graph[curr])
            {
                st.push(i);
            }
        }
    }
    return c;
}
int main(){

    int n , m, a, b;
    
    long long int ans=0,cnt;
    cin >> n >> m;

    for(int i = 0; i <= n; i++) graph[i].clear();
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    vector<bool> vis(n+1);
    for(int i = 0; i <= n; i++) vis[i] = false;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            cnt = dfs(i,vis);
            ans += (cnt*(n-cnt));
        }
    }

    cout << ans/2ll << endl;



    return 0;
}