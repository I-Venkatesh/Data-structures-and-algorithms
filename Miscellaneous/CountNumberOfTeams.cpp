class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans=0;
        for(int i=0;i<rating.size();i++)
        {
            int a=0,b=0;
            for(int j=i+1;j<rating.size();j++)
            {
                if(rating[j]>rating[i])
                {
                    b++;
                }
            }
             for(int j=i-1;j>=0;j--)
            {
                if(rating[j]<rating[i])
                {
                    a++;
                }
            }
            if(a>0&&b>0)
            {
                ans+=(a*b);
            }
        }
        for(int i=0;i<rating.size();i++)
        {
            int a=0,b=0;
            for(int j=i+1;j<rating.size();j++)
            {
                if(rating[j]<rating[i])
                {
                    b++;
                }
            }
             for(int j=i-1;j>=0;j--)
            {
                if(rating[j]>rating[i])
                {
                    a++;
                }
            }
            if(a>0&&b>0)
            {
                ans+=(a*b);
            }
        }
        return ans; 
    }
};