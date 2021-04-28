using namespace std;
#include<bits/stdc++.h>
int main(){
    int test;
    cin>>test;
    while (test--)
    {
        int num;
        cin>>num;
        int arr[num];
        for(int i=0;i<num;i++)
        {
            cin>>arr[i];
        }
        long long int ans=0,c=0;
        for(int i=1;i<num;i++)
        {
            if(arr[i]>=arr[i-1])
            {
                c++;
            }
            else{
                ans+=(c*(c+1))/2;
                c=0;
            }
        }
        if(c>0)
        {
            ans+=(c*(c+1))/2;
        }
        cout<<ans+num<<"\n";
    }
    
}