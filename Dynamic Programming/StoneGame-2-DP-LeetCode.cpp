class Solution {
public:
    int dp[505][505];
    int calc(vector<int>& piles,int current,int M)
    {
        if(current>=piles.size())
        {
            return 0;
        }
        if(dp[current][M]!=-1)
        {
            return dp[current][M];
        }
        int tot=0,ans=INT_MIN;
        for(int i=0;i<2*M;i++)
        {
            if(current+i<piles.size())
            {
                tot+=piles[current+i];
                ans=max(ans,tot-calc(piles,current+i+1,max(M,i+1)));
            }
        }
        return dp[current][M]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        for(auto i:piles)
        {
            sum+=i;
        }
        int diff=calc(piles,0,1);
        return (sum+diff)/2;
    }
};