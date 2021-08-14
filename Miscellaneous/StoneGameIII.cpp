class Solution {
public:
    int dp[50001];
    int solve(vector<int>& stoneValue,int index)
    {
        if(index>=stoneValue.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int sum=0,ans=INT_MIN,size=stoneValue.size();
        for(int i=index;i<min(index+3,size);i++)
        {
            sum+=stoneValue[i];
            ans=max(ans,(sum-solve(stoneValue,i+1)));
        }
        return dp[index]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(auto i:stoneValue)
        {
            ans+=i;
        }
        int res=solve(stoneValue,0);
        if(res==0)
        {
            return "Tie";
        }
        else if(res<0)
        {
            return "Bob";
        }
        return "Alice";
    }
};class Solution {
public:
    int dp[50001];
    int solve(vector<int>& stoneValue,int index)
    {
        if(index>=stoneValue.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int sum=0,ans=INT_MIN,size=stoneValue.size();
        for(int i=index;i<min(index+3,size);i++)
        {
            sum+=stoneValue[i];
            ans=max(ans,(sum-solve(stoneValue,i+1)));
        }
        return dp[index]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(auto i:stoneValue)
        {
            ans+=i;
        }
        int res=solve(stoneValue,0);
        if(res==0)
        {
            return "Tie";
        }
        else if(res<0)
        {
            return "Bob";
        }
        return "Alice";
    }
};