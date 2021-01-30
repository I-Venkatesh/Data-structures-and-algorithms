using namespace std;
#include<bits/stdc++.h>
int countBitsFlip(int a, int b)
{
    // cout<<((a>>40)&1)<<"\n";
    int c=0;
    while(a&&b)
    {
        if((a&1)!=(b&1))
        {
            c++;
        }
        a=a>>1;
        b=b>>1;
    }
    if(a)
    {
        while(a)
        {
            if(a&1)
            {
                c++;
            }
            a=a>>1;
        }
    }
    if(b)
    {
        while(b)
        {
            if(b&1)
            {
                c++;
            }
            b=b>>1;
        }
    }
    return c;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<countBitsFlip(a,b)<<"\n";
}