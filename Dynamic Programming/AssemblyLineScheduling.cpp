using namespace std;
#include<bits/stdc++.h>
int n=4;
int dp[100][100];
int carAssembly(int a[][4],int t[][4],int i,int j,int e[2])
{
    if(j==3)
    {
        if(i==0)
        {
            return dp[i][j]=a[i][j]+e[0];
        }
        else{
            return dp[i][j]=a[i][j]+e[1];
        }
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int m=(i==0)? (min(carAssembly(a,t,i+1,j+1,e)+a[i][j]+t[i][j+1],carAssembly(a,t,i,j+1,e)+a[i][j])):(min(carAssembly(a,t,i-1,j+1,e)+a[i][j]+t[i][j+1],carAssembly(a,t,i,j+1,e)+a[i][j]));
    return dp[i][j]=m;
}
int main()
{
    int a[2][4] = {{4, 5, 3, 2}, 
                   {2, 10, 1, 4}}; 
    int t[2][4] = {{0, 7, 4, 5}, 
                   {0, 9, 2, 8}}; 
    int e[2] = {10, 12}, x[2] = {18, 7};
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
        {
            dp[i][j]=-1;
        }
    }
    int line1=e[0]+carAssembly(a, t, 0,0,x); 
    int line2=e[1]+carAssembly(a, t, 1,0,x);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<min(line1,line2)<<"\n";
}