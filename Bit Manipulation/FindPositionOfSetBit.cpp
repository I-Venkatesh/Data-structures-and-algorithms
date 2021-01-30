using namespace std;
#include<bits/stdc++.h>
int main()
{
    int n;
    cin>>n;
    int pos=0,count=0;
    while(n!=0)
    {
        if(n&1)
        {
            count++;
        }
        n=n>>1;
        pos++;
    }
    if(count>1)
    {
        cout<<-1<<"\n";
    }
    else{
        cout<<pos<<"\n";
    }
}