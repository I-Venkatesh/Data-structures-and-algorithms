using namespace std;
#include<bits/stdc++.h>
int main()
{
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<"NO"<<"\n";
    }
    if((n&(n-1))==0)
    {
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
}