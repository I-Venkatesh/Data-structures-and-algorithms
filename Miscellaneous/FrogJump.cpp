class Solution {
public:
    map<pair<int,int>,bool> dp;
    int solve(int steps, vector<int>& stones,int curr,unordered_set<int> &mp)
    {
        if(curr==stones.back())
        {
            return 1;
        }
        if(mp.find(curr)==mp.end())
        {
            return 0;
        }
        if(dp.find({steps,curr})!=dp.end())
        {
            return dp[{steps,curr}];
        }
        bool x=false,y=false,z=false;
        if(steps-1>0)
        {
            x=solve(steps-1,stones,curr+steps-1,mp);
        }
        if(!x)
        {
            y=solve(steps,stones,curr+steps,mp);
        }
        if(!x&&!y)
        {
            z=solve(steps+1,stones,curr+steps+1,mp);
        }
        return dp[{steps,curr}]=x|y|z;
    }
    bool canCross(vector<int>& stones) {
        unordered_set<int> st(stones.begin(),stones.end());
        if(stones[1]!=1)
        {
            return false;
        }
        return solve(1,stones,1,st);
    }
};