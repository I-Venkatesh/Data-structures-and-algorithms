#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll findSubarray(vector<ll> arr, int n ) {
    long long int sum=0;
    unordered_map<ll,ll> mp;
    ll count=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
        {
            count++;
        }
        if(mp[sum]!=0)
        {
            count+=mp[sum];
        }
        mp[sum]++;
    }
    return count;
}
int main()
{
    int test;
    test=1;
    while (test--)
    {
        int num;
        cin >> num;
        vector<ll> arr(num);
        for (int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
        cout << findSubarray(arr, num) << "\n";
    }
    return 0;
}