class Solution {
  public:
    int dp[1001][500][2];
    int helper(int K,int N,int* A,int option,int i)
    {
        if(K==0||i>=N)
        {
            return 0;
        }
        if(dp[i][K][option]!=-1)
        {
            return dp[i][K][option];
        }
        int inc=(option==0?-A[i]:A[i])+helper(K-1,N,A,(option==1?0:1),i+1);
        int ex=helper(K,N,A,option,i+1);
        return dp[i][K][option]=max(inc,ex);
    }
    int maxProfit(int K, int N, int A[]) {
        memset(dp,-1,sizeof(dp));
        return helper(2*K,N,A,0,0);
    }
};