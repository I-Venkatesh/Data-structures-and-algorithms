class Solution {
public:
    int dp[101][101][601];
    int calc(vector<pair<int,int>> &counts,int m,int n,int currZero,int currOne,int currPos)
    {
        if(currZero>m||currOne>n||currPos>=counts.size())
        {
            return 0;
        }
        if(dp[currZero][currOne][currPos]!=-1)
        {
            return dp[currZero][currOne][currPos];
        }
        int add=0;
        if(currZero+counts[currPos].first<=m&&currOne+counts[currPos].second<=n)
        {
             add=1+calc(counts,m,n,currZero+counts[currPos].first,currOne+counts[currPos].second,currPos+1);
        }
        int leave=calc(counts,m,n,currZero,currOne,currPos+1);
        return dp[currZero][currOne][currPos]=max(add,leave);
                                    
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> counts;
        memset(dp,-1,sizeof(dp));
        for(auto i:strs)
        {
            int zero=0,one=0;
            for(int j=0;j<i.length();j++)
            {
                if(i[j]=='0')
                {
                    zero++;
                }
                else
                {
                    one++;
                }
            }
            counts.push_back({zero,one});
        }
        return calc(counts,m,n,0,0,0);
    }
};