using namespace std;
#include <bits/stdc++.h>
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    deque<pair<int, int>> dq;
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size(); i++)
    {
        int x = intervals[i][0];
        int y = intervals[i][1];
        dq.push_back({x, y});
    }
    while (!dq.empty() && dq.size() != 1)
    {
        pair<int, int> x = dq.front();
        dq.pop_front();
        pair<int, int> y = dq.front();
        dq.pop_front();
        if (x.second < y.first)
        {
            vector<int> temp;
            temp.push_back(x.first);
            temp.push_back(x.second);
            ans.push_back(temp);
            dq.push_back(y);
            sort(dq.begin(), dq.end());
        }
        else
        {
            vector<int> z;
            int s = x.first;
            z.push_back(s);
            int v = max(x.second, y.second);
            z.push_back(v);
            dq.push_front({s, v});
        }
    }
    if (dq.size() == 1)
    {
        pair<int, int> z = dq.front();
        vector<int> temp;
        temp.push_back(z.first);
        temp.push_back(z.second);
        ans.push_back(temp);
    }
    return ans;
}
int main()
{
    int test;
    test = 1;
    while (test--)
    {
        int n;
        cin>>n;
        vector<vector<int>> arr;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            int x,y;
            cin>>x>>y;
            temp.push_back(x);
            temp.push_back(y);
            arr.push_back(temp);
        }
        vector<vector<int>> ans=merge(arr);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
        }
    }
    return 0;
}