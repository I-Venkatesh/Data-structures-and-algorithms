class Solution {
public:
    int dp[1001];
    int calc(int curr,int n,int copied)
    {
        if(curr>n)
        {
            return 10000;
        }
        if(curr==n)
        {
            return 1;
        }
        int copy=INT_MAX,paste=INT_MAX;
        copy=2+calc(2*curr,n,curr);
        paste=1+calc(curr+copied,n,copied);
        return min(copy,paste);
    }
    int minSteps(int n) {
        if(n==1)
        {
            return 0;
        }
        memset(dp,-1,sizeof(dp));
        return calc(1,n,1);
        
    }
};