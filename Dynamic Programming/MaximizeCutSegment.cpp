using namespace std;
#include<bits/stdc++.h>
int dp[100009];
int cut(int n,int x,int y,int z)
{
    if(n==0)
    {
        return 0;
    }
    if(n<0)
    {
        return INT_MIN;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int a=1+cut(n-x,x,y,z);
    int b=1+cut(n-y,x,y,z);
    int c=1+cut(n-z,x,y,z);
    return dp[n]=max(a,max(b,c));
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    for(int i=0;i<100005;i++)
    {
        dp[i]=-1;
    }
    int ans=cut(n,x,y,z);
    if(ans<0)
    {
        return 0;
    }
    return ans;
}
int main()
{
    cout<<maximizeTheCuts(10,2,1,1);
}