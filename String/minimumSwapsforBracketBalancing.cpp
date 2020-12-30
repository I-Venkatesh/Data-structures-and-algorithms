#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int test;
	cin>>test;
	while(test--)
	{
	    int num;
	    cin>>num;
	    string s;
	    cin>>s;
	   int swap=0,right=0,left=0,imbalance=0;
	   for(int i=0;i<num;i++)
	   {
	       if(s[i]=='[')
	       {
	           left++;
	           if(imbalance>0)
	           {
	               swap+=imbalance;
	               imbalance--;
	           }
	       }
	       else if(s[i]==']')
	       {
	           right++;
	           imbalance=right-left;
	       }
	       
	   }
	   cout<<swap<<"\n";
	}
    return 0;
}