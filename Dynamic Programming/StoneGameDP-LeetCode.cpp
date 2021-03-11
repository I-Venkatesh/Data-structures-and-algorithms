class Solution {
public:
    int dp[501][501];
    int calc(vector<int>& piles,int i,int j)
    {
        if(i>j)
        {
            return INT_MIN;
        }
        if(i+1==j)
        {
            return max(piles[i],piles[j]);
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int left=min(piles[i]+calc(piles,i+2,j),piles[i]+calc(piles,i+1,j-1));
        int right=min(piles[j]+calc(piles,i,j-2),piles[j]+calc(piles,i+1,j-1));
        return dp[i][j]=max(left,right);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int first=calc(piles,0,piles.size()-1);
        int sum=0;
        for(auto i:piles)
        {
            sum+=i;
        }
        int second=sum-first;
        if(first>second)
        {
            return true;
        }
        return false;
    }
};