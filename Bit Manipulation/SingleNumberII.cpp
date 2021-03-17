class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long long int ans=0;
        for(int i=31;i>=0;i--)
        {
            int cnt=0;
            for(auto j:nums)
            {
                if(j&(1<<i))
                {
                    cnt++;
                }
            }
            cnt%=3;
            if(cnt&1)
            {
                ans+=pow(2,i);
            }
        }
        return ans;
    }
};