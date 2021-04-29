using namespace std;
#include<bits/stdc++.h>
int dp[1000006];
long long int calc(int num)
{
    if(num<0)
    {
        return 0;
    }
    if(num==0)
    {
        return 1;
    }
    if(dp[num]!=-1)
    {
        return dp[num];
    }
    long long int a=calc(num-2)%1000000009;
    long long int b=calc(num-3)%1000000009;
    return dp[num]=(a+b)%1000000009;
}
int main(){
    int test;
    cin>>test;
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=1000001;i++)
    {
        if(i-2<0||i-3<0)
        {
            dp[i]=0;
        }
        if(i==0)
        {
            dp[i]=1;
        }
        else{
            dp[i]=((dp[i-2]%1000000009)+(dp[i-3]%1000000009))%1000000009;
        }
    }
    while (test--)
    {
        int num;
        cin>>num;
        cout<<dp[num]<<"\n";
    }
    
}