class Solution {
public:
    void nextPerm(vector<int>& nums)
    {
        int i=nums.size()-2;
        while(i>=0&&nums[i]>nums[i+1])
        {
            i--;
        }
        // cout<<nums[i]<<" "<<nums[i+1]<<"\n";
        int j=nums.size()-1;
        if(i!=-1)
        {
            while(i<j&&nums[j]<nums[i])
            {
                j--;
            }
            swap(nums[i],nums[j]);
        }
        i++;
        j=nums.size()-1;
        while(i<=j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp=nums;
        nextPerm(nums);
        while(1)
        {
            ans.push_back(nums);
            bool ok=true;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]!=temp[i])
                {
                    ok=false;
                }
            }
            if(ok)
            {
                break;
            }
            nextPerm(nums);
        }
        return ans;
    }
};