#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cin >> num;
    string arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    map<string, int> counter;
    for (int i = 0; i < num; i++)
    {
        counter[arr[i]]++;
    }
    vector<pair<int,string>> ans;
    for(auto i:counter){
        ans.push_back({i.second,i.first});
    }
    sort(ans.rbegin(),ans.rend());
    cout<<ans[1].second<<"\n";
}