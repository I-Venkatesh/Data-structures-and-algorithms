class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int ans=0;
        for(auto i:mp)
        {
            if(k-i.first>0)
            {
                if(2*i.first==k)
                {
                    ans+=i.second/2;
                    i.second=i.second%2;
                }
                else if(mp[k-i.first]>0)
                {
                    int mini=min(i.second,mp[k-i.first]);
                    ans+=mini;
                    mp[i.first]-=mini;
                    mp[k-i.first]-=mini;
                }
            }
        }
        return ans;
    }
};