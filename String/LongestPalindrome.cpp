#include <bits/stdc++.h>
using namespace std;
int pal(string s)
{
    int size=s.size();
    if(size%2==0)
    {
        size=size/2;
        size--;
    }
    else
    {
        size/=2;
    }
    for(int i=0;i<=size;i++)
    {
        if(s[i]!=s[s.size()-1-i])
        {
            return 0;
        }
    }
    return 1;
}
int main() {
	//code
	int test;
	cin>>test;
	while(test--)
	{
	    string s;
	    cin>>s;
	    vector<string> arr; 
	    for(int i=0;i<s.size();i++)
	    {
	        string temp="";
	        for(int j=i;j<s.size();j++)
	        {
	            temp+=s[j];
	            arr.push_back(temp);
	        }
	    }
	    string ans;
	    int maxi=0;
	    for(int i=0;i<arr.size();i++)
	    {
	        if(pal(arr[i]))
	        {
	            if(arr[i].size()>maxi)
	            {
	                maxi=arr[i].size();
	                ans=arr[i];
	            }
	        }
	    }
	    cout<<ans<<"\n";
	    
	}
	return 0;
}