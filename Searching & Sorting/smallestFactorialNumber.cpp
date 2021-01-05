#include <bits/stdc++.h>
using namespace std;
int check(int p,int n)
{
    int temp=p,count=0,f=5;
    while(f<=temp)
    {
        count+=temp/f;
        f=f*5;
    }
    return (count>=n);
}
int main()
{
    long long int ans=0;
    int n;
    cin>>n;
    int l=0,r=5*n;
    while(l<r)
    {
        int mid=(l+(r-l)/2);
        if(check(mid,n)){
            r=mid;
            ans=r;
        }
        else{
            l=mid+1;
        }
    }
    cout<<l<<"\n";
}