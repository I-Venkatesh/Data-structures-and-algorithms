using namespace std;
#include<bits/stdc++.h>
int main()
{
    int a,b;
    cin>>a>>b;
    int res=0;
    while(a-b>0)
    {
        int x=0;
        while(a-(b<<1<<x)>=0)
        {
            x++;
        }
        res+=1<<x;
        a-=b<<x;
    }
    cout<<res<<"\n";
}