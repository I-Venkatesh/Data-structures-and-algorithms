#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    int ME=arr[0],count=1;
    for(int i=1;i<N;i++)
    {
        if(arr[i]==ME)
        {
            count++;
        }
        else{
            count--;
            if(count==0)
            {
                ME=arr[i];
                count++;
            }
        }
    }
    int c=0;
    for(int i=0;i<N;i++)
    {
        if(arr[i]==ME)
        {
            c++;
        }
    }
    if(c>N/2)
    {
        cout<<ME<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }
    return 0;
}