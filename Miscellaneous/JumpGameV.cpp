class Solution {
public:
    int dp[1001];
    int helper(vector<int>& arr,int curr,int d)
    {
        if(dp[curr]!=-1)
        {
            return dp[curr];
        }
        int ans=1;
        int n=arr.size();
        int size=min(curr+d+1,n);
        for(int i=curr+1;i<size;i++)
        {
            if(arr[curr]>arr[i])
            {
                if(dp[i]==-1)
                {
                    dp[i]=1+helper(arr,i,d);
                }
                ans=max(dp[i],ans);
            }
            else{
                break;
            }
        }
        for(int i=curr-1;i>max(curr-d-1,-1);i--)
        {
            if(arr[curr]>arr[i])
            {
                if(dp[i]==-1)
                {
                    dp[i]=1+helper(arr,i,d);
                }
                ans=max(dp[i],ans);
            }
            else{
                break;
            }
        }
        return ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        
        int maxi=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<arr.size();i++)
        {
            maxi=max(maxi,helper(arr,i,d));
        }
        return maxi;
    }
};