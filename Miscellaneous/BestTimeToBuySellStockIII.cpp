class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int left[prices.size()];
        int right[prices.size()];
        left[0]=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            left[i]=max(prices[i]-mini,left[i-1]);
            mini=min(mini,prices[i]);
        }
        right[prices.size()-1]=0;
        int maxi=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--)
        {
            right[i]=max(maxi-prices[i],right[i+1]);
            maxi=max(maxi,prices[i]);
        }
        int ans=right[0];
        for(int i=1;i<prices.size();i++)
        {
            ans=max(left[i-1]+right[i],ans);
        }
        return ans;
    }
};