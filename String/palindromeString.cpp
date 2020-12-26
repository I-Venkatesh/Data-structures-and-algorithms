using namespace std;
#include<bits/stdc++.h>
int main()
{
    string S;
    cin>>S;
    bool ok=true;
     int size=S.size();
	    if(size%2==0)
	    {
	        size=(size/2)-1;
	    }
	    else
	    {
	        size/=2;
	    }
	    for(int i=0;i<=size;i++)
	    {
	        if(S[i]!=S[S.size()-1-i])
	        {
	            ok=false;
	        }
	    }
        if(ok)
        {
            cout<<"Palindrome"<<"\n";
        }
        else{
            cout<<"Not palindrome"<<"\n";
        }
}