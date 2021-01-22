using namespace std;
#include<bits/stdc++.h>
int dp[10000];
int maxSub(int num,int arr[])
{
    int sum[num];
    if(num>=1)
    {
        sum[0]=arr[0];
    }
    if(num>=2)
    {
        sum[1]=arr[0]+arr[1];
    }
    if(num>2)
    {
        sum[2]=max(sum[1], max(arr[1] + arr[2], arr[0] + arr[2])); 
    }
    for(int i=3;i<num;i++)
    {
        sum[i]=max(max(sum[i-1],sum[i-2]+arr[i]),arr[i]+arr[i-1]+sum[i-3]);
    }
    return sum[num-1];
}
int main()
{
    int arr[5]={1,2,3,4,5};
    cout<<maxSub(5,arr)<<"\n";
}