class Solution {
public:
    int dp[1000005];
    int calc(vector<int>& nums,int index)
    {
        if(index>=nums.size()-1)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int ans=100000005;
        for(int i=1;i<=nums[index];i++)
        {
             ans=min(ans,1+calc(nums,index+i));
        }
        return dp[index]=ans;
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int farthest=nums[0];
        int currentFar=nums[0];
        int jumps=1;
          if(nums[0]==0 || nums.size()==1){
            return 0;
        }
        
        for(int i=1;i<nums.size();i++)
        {
            if(i==nums.size()-1)
            {
                return jumps;
            }
            farthest=max(nums[i]+i,farthest);
            if(currentFar==i)
            {
                jumps++;
                currentFar=farthest;
            }
        }
        return jumps;
    }
};