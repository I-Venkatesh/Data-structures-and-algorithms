using namespace std;
#include <bits/stdc++.h>
long long int dp[1000][1000];
long long int solve(long long int n,int m[],int i)
{   
    if(n<0||i>=3)
    {
        return 0;
    }
	else if(n==0)
	{
	    return 1;
	}
    else if(dp[i][n]!=-1)
	{
	    return dp[i][n];
	}
	int left=solve(n-m[i],m,i);
	int right=solve(n,m,i+1);
	return dp[i][n]=left+right;
}
long long int count(long long int n)
{
    memset(dp,-1,sizeof(dp));
    int m[3]={3,5,10};
    return solve(n,m,0);
}
int main()
{
    int num;
    cin>>num;
    cout<<count(num)<<"\n";
}