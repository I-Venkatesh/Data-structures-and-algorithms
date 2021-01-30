using namespace std;
#include<bits/stdc++.h>
int main()
{
    int N;
    cin>>N;
    int count=0;
    while(N)
    {
        if(N&1)
        {
            count++;
        }
        N=N>>1;
    }
    cout<<count<<"\n";
}