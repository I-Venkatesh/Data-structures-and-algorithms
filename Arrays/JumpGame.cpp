class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr=nums[0]-1;
        if(nums[0]==0&&nums.size()>1)
        {
            return 0;
        }
        for(int i=1;i<nums.size();i++)
        {
            if(i==nums.size()-1)
            {
                return 1;
            }
            if(nums[i]>=curr)
            {
                curr=nums[i];
            }
            if(curr<=0)
            {
                return 0;
            }
            else
            {
                curr--;
            }
        }
        return 1;
    }
};