#include <bits/stdc++.h>
using namespace std;
int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int freq[30];
	    memset(freq,0,sizeof(freq));
	    string s;
	    cin>>s;
	    for(int i=0;i<s.length();i++)
	    {
	        freq[s[i]-'a']++;
	    }
	    vector<int> arr;
	    for(int i=0;i<30;i++)
	    {
	        if(freq[i]>0)
	        {
	            arr.push_back(freq[i]);
	        }
	    }
	    sort(arr.rbegin(),arr.rend());
	    int a=arr[0],b=0;
	    for(int i=1;i<arr.size();i++)
	    {
	        b+=arr[i];
	    }
	    a--;
	    if(b>=a)
	    {
	        cout<<1<<"\n";
	    }
	    else{
	        cout<<0<<"\n";
	    }
	}
	return 0;
}
