#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans;
    for (int i = 0; i < num; i++)
    {
        if (arr[i] == i + 1)
        {
            ans.push_back(arr[i]);
        }
    }
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    return 0;
}