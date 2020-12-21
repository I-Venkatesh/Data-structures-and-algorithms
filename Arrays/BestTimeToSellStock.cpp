
using namespace std;
#include <bits/stdc++.h>
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n == 0)
    {
        return 0;
    }
    int arr[n];
    arr[0] = 0;
    int mini = prices[0];
    for (int i = 1; i < n; i++)
    {
        arr[i] = mini;
        mini = min(mini, prices[i]);
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans = max(ans, prices[i] - arr[i]);
    }
    return ans;
}
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << maxProfit(arr) << "\n";
    }
}