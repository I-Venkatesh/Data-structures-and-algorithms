using namespace std;
#include<bits/stdc++.h>
int main()
{
    int n,W;
    cin>>n>>W;
    long long int knap[n+1][W+1];
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        arr.push_back({x,y});
    } 
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0||j==0)
            {
                knap[i][j]=0;
            }
            else{
                if(j-arr[i-1].first>=0)
                {
                    knap[i][j]=max(knap[i-1][j],arr[i-1].second+knap[i-1][j-arr[i-1].first]);
                }
                else 
                {
                    knap[i][j]=knap[i-1][j];
                }
                
            }
            
        }
    }
    cout<<knap[n][W]<<"\n";
}