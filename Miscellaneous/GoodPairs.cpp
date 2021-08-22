class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int freq[101];
        memset(freq,0,sizeof(freq));
        for(auto i:nums)
        {
            freq[i]++;
        }
        int ans=0;
        for(int i=0;i<101;i++)
        {
            if(freq[i]>1)
            {
                ans+=(freq[i]*(freq[i]-1))/2;
            }
        }
        return ans;
    }
};