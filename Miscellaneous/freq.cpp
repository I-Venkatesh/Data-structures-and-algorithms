using namespace std;
#include<bits/stdc++.h>
int main()
{
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    map<int,pair<int,int>> mp;
    for(int i=0;i<num;i++)
    {
        mp[arr[i]]++;
    }
    for(auto i:mp)
    {
        cout<<i.first<<" "<<i.second<<"\n";
    }
}