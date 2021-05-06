class Solution {
public:
    int visited[1000005];
    int dfs(vector<int>& nums,int num)
    {
        visited[num]=1;
        int ans=0;
        if(visited[nums[num]]==0)
        {
            ans=1+dfs(nums,nums[num]);
        }
        return ans;
    }
    int arrayNesting(vector<int>& nums) {
        memset(visited,0,sizeof(visited));
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(visited[i]==0)
            {
                ans=max(ans,1+dfs(nums,i));
            }
        }
        return ans;
    }
};