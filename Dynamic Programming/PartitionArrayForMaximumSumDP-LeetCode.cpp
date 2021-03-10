class Solution {
public:
    int dp[100005];
    int calc(vector<int>& arr, int k, int j)
    {
        if(j==arr.size())
        {
            return 0;
        }
        else if(dp[j]!=0)
        {
            return dp[j];
        }
        else{
            int res=-1;
            for(int i=j;i<arr.size();i++)
            {
                res=max(res,arr[i]);
                if((i-j+1)<=k)
                {
                    dp[j]=max(dp[j],res*(i-j+1)+calc(arr,k,i+1));
                }
            }
            return dp[j];
        }
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,0,sizeof(dp));
        return calc(arr,k,0);
        
    }
};