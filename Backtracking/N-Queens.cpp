using namespace std;
#include<bits/stdc++.h>
int X[4]={-1,0,0,1};
int Y[4]={0,-1,1,0};
int arr[100][100];
bool check(int row,int col,int num)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (arr[row][i])
            return false;
    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (arr[i][j])
            return false;
    for (i=row, j=col; j>=0 && i<num; i++, j--)
        if (arr[i][j])
            return false;

    return true;
}
bool solve(int col,int num)
{
    if(col==num)
    {
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num;j++)
            {
                cout<<arr[i][j];
            }
            cout<<"\n";
        }
        cout<<"\n";
        return true;
    }
    bool res=false;
    for(int i=0;i<num;i++)
    {
        if(check(i,col,num))
        {
            arr[i][col]=1;
            res=solve(col+1,num)||res;
            arr[i][col]=0;
        }
    }
    return res;
}
int main()
{
    int num;
    cin>>num;
    solve(0,num);
}