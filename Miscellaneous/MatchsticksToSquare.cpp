class Solution {
public:
    int solve(vector<int>& match,int* sides,int curr)
    {
        if(curr==match.size())
        {
            for(int i=0;i<4;i++)
            {
                if(sides[i]!=0)
                {
                    return false;
                }
            }
            return true;
        }
       for(int i=0;i<4;i++)
       {
           if(match[curr]>sides[i])
           {
               continue;
           }
           sides[i]-=match[curr];
           if(solve(match,sides,curr+1))
           {
                return true;
           }
           sides[i]+=match[curr];
       }
        return false;
    }
    bool makesquare(vector<int>& matchsticks)
    {
        sort(matchsticks.rbegin(),matchsticks.rend());
        int sum=0;
        for(auto i:matchsticks)
        {
            sum+=i;
        }
        if(sum%4!=0)
        {
            return false;
        }
        int sides[4];
        for(int i=0;i<4;i++)
        {
            sides[i]=sum/4;
        }
        return solve(matchsticks,sides,0);
    }
};