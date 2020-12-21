//Complete this function
using namespace std;
#include<bits/stdc++.h>
bool subArrayExists(int arr[], int n)
{
    //Your code here
    map<int,int> m;
    long long int s=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            return 1;
        }
        else
        {
            s+=arr[i];
            if(s==0)
            {
                return 1;
            }
            if(m[s]==1)
            {
                return 1;
            }
            else
            {
                m[s]=1;
            }
        }
    }
    return 0;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(subArrayExists(arr,n))
    {
        cout<<"YES"<<"\n";
    }
    else
    {
        cout<<"NO"<<"\n";
    }
    
}