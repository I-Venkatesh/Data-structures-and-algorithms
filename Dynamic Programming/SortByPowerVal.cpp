class Solution {
public:
    int dp[1000005];
    int calc(int n)
    {
        if(n==1)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int steps=0;
        if(n%2==0)
        {
            steps=1+calc(n/2);
        }
        else{
            steps=1+calc((3*n)+1);
        }
        return dp[n]=steps;
    }
    int getKth(int lo, int hi, int k) {
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=1000;i++)
        {
            dp[i]=calc(i);
        }
        vector<pair<int,int>> arr;
        for(int i=lo;i<=hi;i++)
        {
            arr.push_back({dp[i],i});
        }
        sort(arr.begin(),arr.end());
        return arr[k-1].second;
    }
};