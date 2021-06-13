class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=true;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int c=0;
            if(mp[nums[i]-1]==false)
            {
                int x=nums[i];
                while(mp[x]==true)
                {
                    x++;
                    c++;
                }
                ans=max(ans,c);
            }
        }
        return ans;
    }
};