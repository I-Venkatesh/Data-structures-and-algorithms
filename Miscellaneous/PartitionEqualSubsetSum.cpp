class Solution {
public:
    // int dp[30000][201];
    // bool calc(vector<int>& nums,int tot,int index)
    // {
    //     if(tot==0)
    //     {
    //         return true;
    //     }
    //     if(tot<0||index>=nums.size())
    //     {
    //         return false;
    //     }
    //     if(dp[tot][index]!=-1)
    //     {
    //         return dp[tot][index];
    //     }
    //     return dp[tot][index]=calc(nums,tot-nums[index],index+1)||calc(nums,tot,index+1);
    // }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        
        if(sum%2==0)
        {
            sort(nums.begin(),nums.end());
            int tot=sum/2;
            bool dp[nums.size()+1][tot+1];
            for(int i=0;i<=nums.size();i++)
            {
                dp[i][0]=true;
            }
            for(int i=0;i<=tot;i++)
            {
                dp[0][i]=false;
            }
            for(int i=1;i<=nums.size();i++)
            {
                for(int j=1;j<=tot;j++)
                {
                    if(j-nums[i-1]>=0)
                    {
                        dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            return dp[nums.size()][tot];
        }
        return false;
    }
};