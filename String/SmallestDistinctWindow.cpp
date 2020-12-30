#include <bits/stdc++.h>
using namespace std;
int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    string s;
	    cin>>s;
	    int freq[30];
	    int freq2[30];
	    int c=0;
	    memset(freq,0,sizeof(freq));
	    memset(freq2,0,sizeof(freq2));
	    for(int i=0;i<s.size();i++)
	    {
	        if(freq[s[i]-'a']==0)
	        {
	            c++;
	        }
	        freq[s[i]-'a']++;
	    }
	    int k=0,size=s.length();
	    int i=0,j=0,len=0,maxi=INT_MAX;
	    while(j<size)
	    {
	        while(k<c&&j<size)
	        {
	            if(freq2[s[j]-'a']==0)
                {
                    k++;
                }
                len++;
                freq2[s[j]-'a']++;
                j++;
	        }
	        maxi=min(maxi,len);
	        while(k==c&&i<j)
	        {
	             maxi=min(maxi,len);
	            if(freq2[s[i]-'a']==1)
	            {
	                k--;
	            }
                len--;
                freq2[s[i]-'a']--;
                i++;
	        }
	    }
	    cout<<maxi<<"\n";
	}
	return 0;
}