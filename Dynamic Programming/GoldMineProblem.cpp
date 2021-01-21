using namespace std;
#include<bits/stdc++.h>
int X[]={0,1,-1};
int Y[]={1,1,1};
int ans[100][100];
bool valid(int x,int y,int n,int m)
{
    if(x>=0&&x<n&&y>=0&&y<m)
    {
        return true;
    }
    return false;
}
int fill(int n,int m,int mat[][3])
{
    for(int i=0;i<n;i++)
    {
        ans[i][m-1]=mat[i][m-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            int a = valid(i+X[0],j+Y[0],n,m) == 1 ? ans[i+X[0]][j+Y[0]]:0;
            int b = valid(i+X[1],j+Y[1],n,m) == 1 ? ans[i+X[1]][j+Y[1]]:0;
            int c = valid(i+X[2],j+Y[2],n,m) == 1 ? ans[i+X[2]][j+Y[2]]:0;
            ans[i][j]=mat[i][j]+max(a,max(b,c));
        }
    }
    int answer=0;
    for(int i=0;i<n;i++)
    {
        answer=max(answer,ans[i][0]);
    }
    return answer;
}
int main(){
    int mat[3][3]={{1,3,3},
                   {2,1,4},
                   {0,6,4}};
    int n=3,m=3;
    cout<<fill(n,m,mat)<<"\n";
}