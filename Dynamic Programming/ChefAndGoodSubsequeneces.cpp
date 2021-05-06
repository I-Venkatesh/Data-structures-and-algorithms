using namespace std;
#include<bits/stdc++.h>
int num,k;
int dp[1008];
int calc(int curr,int kCurr)
{
    if(curr>=num||kCurr>=k)
    {
        return 0;
    }
    int left=0;
    if(dp[curr]==0)
    {
        dp[curr]=1;
        left=1+calc(curr+1,kCurr+1);
        dp[curr]=0;
        kCurr--;
    }
    else{
        left=calc(curr+1,kCurr+1);
    }
    return left;
}
int main(){
    cin>>num>>k;
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    cout<<calc(0,0);
}