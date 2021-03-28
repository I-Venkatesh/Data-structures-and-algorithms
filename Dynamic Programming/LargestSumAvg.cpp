class Solution {
public:
    double dp[1001][1001];
    double calc(vector<int>& A, int K,int start)
    {
        if(K<=0)
        {
            return 0;
        }
        if(dp[K][start]!=-1)
        {
            return dp[K][start];
        }
        double sum=0.0,res=0.0;
        for(int i=start;i<A.size();i++)
        {
            sum+=A[i];
            if(K!=1||i==A.size()-1)
            {
                res=max(res,sum/(i-start+1)+calc(A,K-1,i+1));
            }
        }
        return dp[K][start]=res;
    }
    double largestSumOfAverages(vector<int>& A, int K) {
        for(int i=0;i<1001;i++)
        {
            for(int j=0;j<1001;j++)
            {
                dp[i][j]=-1.0;
            }
        }
        return calc(A,K,0);
    }
};