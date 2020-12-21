using namespace std;
#include <bits/stdc++.h>
int getPairsCount(vector<int> arr, int n, int k)
{
    // code here
    int freq[1000007];
    int visited[1000007];
    long long int ans = 0;
    memset(freq, 0, sizeof(freq));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (int i = 1; i < k; i++)
    {
        if (i == (k - i))
        {
            if (freq[i] > 1)
            {
                ans += (freq[i] * (freq[i] - 1)) / 2;
            }
        }
        else if (freq[i] > 0 && freq[k - i] > 0 && visited[i] == 0 && visited[k - i] == 0)
        {
            visited[i] = 1;
            visited[k - i] = 1;
            ans += freq[i] * freq[k - i];
        }
    }
    return ans;
}
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n >>k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << getPairsCount(arr,n,k) << "\n";
    }
}