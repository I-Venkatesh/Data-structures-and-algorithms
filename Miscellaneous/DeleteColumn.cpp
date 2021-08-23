class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int i,j,k;
        int n=strs[0].size();
        int m=strs.size();
        vector<int> dp(n,1);
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                for(k=0;k<m;k++)
                {
                    if(strs[k][j]>strs[k][i])
                        break;
                }
                if(k==m&&dp[i]<1+dp[j])
                {
                    dp[i]=1+dp[j];
                }
            }
        }
        return n-*max_element(dp.begin(),dp.end());
    }
};