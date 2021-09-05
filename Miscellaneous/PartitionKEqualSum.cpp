class Solution {
public:
    int arr[17];
    int solve(vector<int>& nums,int k, int curr)
    {
        if(curr==nums.size())
        {
            for(int i=0;i<k;i++)
            {
                if(arr[k]!=0)
                {
                    return 0;
                }
            }
            return 1;
        }
        bool ans=false;
        for(int i=0;i<k;i++)
        {
            if(nums[curr]>arr[i])
            {
                continue;
            }
            arr[i]-=nums[curr];
            if(solve(nums,k,curr+1))
            {
                return 1;
            }
            arr[i]+=nums[curr];
        }
        return 0;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum=0;
        sort(nums.rbegin(),nums.rend());
        for(auto i:nums)
        {
            sum+=i;
        }
        if(sum%k!=0)
        {
            return false;
        }
        for(int i=0;i<k;i++)
        {
            arr[i]=sum/k;
        }
        return solve(nums,k,0);
    }
};