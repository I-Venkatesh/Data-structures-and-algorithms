class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size()==2)
        {
            return nums;
        }
        long long int x=0;
        for(auto i:nums)
        {
            x=x^i;
        }
        int c=x&(~(x-1));
        int a=0,b=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&c)
            {
                a=a^nums[i];
            }
            else
            {
                b=b^nums[i];
            }
        }
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
