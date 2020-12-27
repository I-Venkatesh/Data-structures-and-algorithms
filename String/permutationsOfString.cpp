#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    string s;
	    vector<string> ans;
	    cin>>s;
	    sort(s.begin(),s.end());
	    do{
	        ans.push_back(s);
	    }while(next_permutation(s.begin(),s.end()));
	    sort(ans.begin(),ans.end());
	    for(auto i:ans)
	    {
	        cout<<i<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}