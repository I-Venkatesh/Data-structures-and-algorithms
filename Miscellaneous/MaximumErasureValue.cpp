class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start=0,curr=0,maxi=0;
        int arr[1000005];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<nums.size();i++)
        {
            while(arr[nums[i]]==1)
            {
                arr[nums[start]]=0;
                curr-=nums[start];
                start++;
            }
            curr+=nums[i];
            arr[nums[i]]=1;
            maxi=max(maxi,curr);
        }
        return maxi;
    }
};