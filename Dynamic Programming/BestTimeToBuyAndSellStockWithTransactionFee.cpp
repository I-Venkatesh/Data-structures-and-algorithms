class Solution {
public:
    int dp[100005][2];
    int calc(vector<int>& prices, int fee,int curr,int option)
    {
        if(curr==prices.size())
        {
            return 0;
        }
        if(dp[curr][option]!=-1)
        {
            return dp[curr][option];
        }
        long long int op1 = 0,op2=0;
        if(option == 0) 
        {
            op1=max(-prices[curr]+calc(prices,fee,curr+1,1),calc(prices,fee,curr+1,option));
        } 
        else
        {
            op2=max(prices[curr]-fee+calc(prices,fee,curr+1,0),calc(prices,fee,curr+1,option));
        }
        return dp[curr][option]=max(op2,op1);
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return calc(prices,fee,0,0);
    }
};