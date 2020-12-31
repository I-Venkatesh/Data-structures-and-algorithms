#include <bits/stdc++.h>
using namespace std;
 
#define R 3
#define C 3
string arr[100][100];
string output[100];
void printAll(int m,int n)
{
    output[m]=arr[m][n];
    if(m==R-1)
    {
        for(int i=0;i<R;i++)
        {
            cout<<output[i]<<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<R;i++)
    {
        if(arr[m+1][i]!="")
        {
            printAll(m+1,i);
        }
    }
}
void print()
{
    for(int i=0;i<C;i++)
    {
        printAll(0,i);
    }
}
using namespace std;
int main()
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>arr[i][j];
        }
    }
   print();
 
   return 0;
}