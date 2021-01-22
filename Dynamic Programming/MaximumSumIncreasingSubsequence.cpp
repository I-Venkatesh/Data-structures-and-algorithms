#include <iostream>
using namespace std;

int maxSumIS(int arr[], int n)
{
    int maxi = 0;
    int dp[n];
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int s = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                s = max(s, dp[j]);
            }
        }
        dp[i] = s + arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}
int main()
{
   int n=5;
   int arr[5]={1,101,2,3,100};
   cout<<maxSumIS(arr,n)<<"\n";
}