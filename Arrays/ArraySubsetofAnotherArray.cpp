#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    cin>>test;
    while(test--)
    {
        int n,m;
        cin>>n>>m;
        int arr1[100005];
        int arr2[100005];
        memset(arr1,0,sizeof(arr1));
        memset(arr2,0,sizeof(arr2));
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            arr1[x]++;
        }
        for(int i=0;i<m;i++)
        {
            int x;
            cin>>x;
            arr2[x]++;
        }
        bool ok=true;

        for(int i=0;i<100005;i++)
        {
            if(arr2[i]>0)
            {
                if(arr1[i]!=arr2[i])
                {
                    ok=false;
                    break;
                }
            }
        }
        if(ok)
        {
            cout<<"Yes"<<"\n";
        }
        else
        {
            cout<<"No"<<"\n";
        }
        
    }
	return 0;
}