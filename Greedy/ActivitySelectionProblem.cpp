using namespace std;
#include<bits/stdc++.h>
int maxMeetings(int start[], int end[], int n) {
    vector<pair<int,int>> arr;
    for(int i=0;i<n;i++)
    {
        arr.push_back({end[i],start[i]});
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    pair<int,int> hold=arr[0];
    for(int i=1;i<n;i++)
    {
        if(hold.first<arr[i].second)
        {
            ans++;
            hold=arr[i];
        }
    }
    return ans+1;
}
int main()
{
    int num;
    cin>>num;
    int start[num],end[num];
    for(int i=0;i<num;i++)
    {
        cin>>start[i];
    }
    for(int i=0;i<num;i++)
    {
        cin>>end[i];
    }
    cout<<maxMeetings(start,end,num)<<"\n";
}