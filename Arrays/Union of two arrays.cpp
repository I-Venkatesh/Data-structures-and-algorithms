using namespace std;
#include<bits/stdc++.h>
int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int n,m;
    	cin>>n>>m;
    	set<int> ans;
    	for(int i=0;i<n*m;i++)
    	{
    	    int x;
    	    cin>>x;
    	    ans.insert(x);
    	}
    	cout<<ans.size()<<"\n";   
	}
	return 0;
}