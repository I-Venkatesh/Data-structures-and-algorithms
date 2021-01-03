#include <bits/stdc++.h>
using namespace std;
long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    long long int ans = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            if (arr[i] + arr[j] + arr[k] >= sum)
            {
                k--;
            }
            else
            {
                ans += k - j;
                j++;
            }
        }
    }
    return ans;
}
int main()
{
    int test;
    test=1;
    while (test--)
    {
        int num;
        long long int k;
        cin >> num>>k;
        long long int arr[num];
        for (int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
        cout << countTriplets(arr, num, k) << "\n";
    }
    return 0;
}