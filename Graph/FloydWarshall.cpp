#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int n;
	    cin>>n;
	    int graph[n][n];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>graph[i][j];
	        }
	    }
	    int dist[n][n];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            dist[i][j]=graph[i][j];
	        }
	    }
	    int INTMAX=1e7;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            for(int k=0;k<n;k++)
	            {
	                if(dist[j][i]==INTMAX||dist[i][k]==INTMAX)
	                {
	                    continue;
	                }
	                else
	                {
	                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
	                }
	            }
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(dist[i][j]==INTMAX)
	            {
	                cout<<"INF"<<" ";
	            }
	            else{
	                cout<<dist[i][j]<<" ";
	            }
	        }
	        cout<<"\n";
	    }
	}
	return 0;
}