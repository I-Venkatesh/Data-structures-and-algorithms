#include <iostream>
using namespace std;

int main() {
	//code
	int test;
	cin>>test;
	while(test--)
	{
	    string s;
	    cin>>s;
	    int a=0,b=0;
	    for(int i=0;i<s.length();i++)
	    {
	        if(i%2==0)
	        {
	            if(s[i]=='1')
	            {
	                a++;
	            }
	        }
	        else{
	            if(s[i]=='0')
	            {
	                a++;
	            }
	        }
	    }
	    for(int i=0;i<s.length();i++)
	    {
	        if(i%2==0)
	        {
	            if(s[i]=='0')
	            {
	                b++;
	            }
	        }
	        else{
	            if(s[i]=='1')
	            {
	                b++;
	            }
	        }
	    }
	    cout<<min(a,b)<<"\n";
	}
	return 0;
}