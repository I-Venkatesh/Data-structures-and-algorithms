class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
        {
            return 0;
        }
        if(nums.size()==1)
        {
            return nums[0];
        }
        int maxProd=0,curr=1;
        for(int i=0;i<nums.size();i++)
        {
            curr*=nums[i];
            maxProd=max(maxProd,curr);
            if(curr==0)
            {
                curr=1;
            }
        }
        curr=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            curr*=nums[i];
            maxProd=max(maxProd,curr);
            if(curr==0)
            {
                curr=1;
            }
        }
        return maxProd;
    }
};