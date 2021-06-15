class Solution {
public:
    int inf=3000;
    // int dp[2501][3001];
//     int calc(vector<int>& nums,int index,int included)
//     {
//         if(index>=nums.size())
//         {
//             return 0;
//         }
//         int inc=0,ex=0;
 
//             if(dp[index][included]!=-1)
//             {
//                 return dp[index][included];
//             }
        
//         if(included==inf)
//         {
//             inc=1+calc(nums,index+1,index);
//             ex=calc(nums,index+1,inf);
//         }
//         else
//         {
//             if(nums[included]<nums[index])
//             {
//                 inc=1+calc(nums,index+1,index);
//             }
//             ex=calc(nums,index+1,included);
//         }

//             return dp[index][included]=max(inc,ex); 
        
//         return 0;
//     }
    int lengthOfLIS(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
       // return max(1+calc(nums,1,0),calc(nums,1,inf));
        int maxi=1;
        int dp[nums.size()];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};