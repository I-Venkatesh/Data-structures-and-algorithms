using namespace std;
#include<bits/stdc++.h>
int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int dp[n+1];
    dp[0]=arr[0];
    int sum=dp[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>dp[i-1]+arr[i])
        {
            dp[i]=arr[i];
            sum=arr[i];
        }
        else{
            dp[i]=dp[i-1]+arr[i];
            sum+=arr[i];
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,dp[i]);
    }
    return maxi;
}
int main()
{
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    cout<<maxSubarraySum(arr,num)<<"\n";
}