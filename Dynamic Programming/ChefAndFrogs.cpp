using namespace std;
#include<bits/stdc++.h>
int main(){
    int test;
    test=1;
    while(test--)
    {
        int num,k,p;
        cin>>num>>k>>p;
        vector<pair<int,int>> arr;
        for(int i=0;i<num;i++)
        {
            int x;
            cin>>x;
            arr.push_back({x,i});
        }
        sort(arr.begin(),arr.end());
        int par[num+1];
         for(int i=0;i<num;i++)
        {
            par[i]=i;
        }
        for(int i=1;i<num;i++)
        {
            if(arr[i].first-arr[i-1].first<=k)
            {
                par[arr[i].second]=par[arr[i-1].second];
            }
        }
        for(int i=0;i<p;i++)
        {
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            if(par[x]==par[y])
            {
                cout<<"Yes"<<'\n';
            }
            else{
                cout<<"No"<<'\n';
            }
        }
    }
}