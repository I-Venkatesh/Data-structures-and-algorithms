#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arr1[n];
    int arr2[m];
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>arr2[i];
    }
    int m1=-1,m2=-1;
    if((n+m)%2==1)
    {
        int i=0,j=0;
        for(int count=0;count<=(n+m)/2;count++)
        {
            if(i<n&&j<m)
            {
                m1=(arr1[i]<arr2[j])?arr1[i++]:arr2[j++];
            }
            else if(i<n)
            {
                m1=arr1[i++];
            }
            else
            {
                m1=arr2[j++];
            }
        }
        cout<<m1<<"\n";
    }
    else
    {
        int i=0,j=0;
        for(int count=0;count<=(n+m)/2;count++)
        {
            m2=m1;
            if(i<n&&j<m)
            {
                m1=(arr1[i]<arr2[j])?arr1[i++]:arr2[j++];
            }
            else if(i<n)
            {
                m1=arr1[i++];
            }
            else
            {
                m1=arr2[j++];
            }
        }
        cout<<(m1+m2)/(1.0*2)<<"\n";
    }
    
}