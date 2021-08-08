stack<int> st;
	int visited[100005];
	void helper(int V, vector<int> adj[]) 
	{
	    visited[V]=1;
	    for(int i=0;i<adj[V].size();i++)
	    {
	        if(!visited[adj[V][i]])
	        {
	            helper(adj[V][i],adj);
	        }
	    }
	    st.push(V);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    memset(visited,0,sizeof(visited));
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	        {
        	    helper(i,adj);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}