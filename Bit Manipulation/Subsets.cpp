class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=0;i<(1<<nums.size());i++)
        {
            int x=i,c=0;
            vector<int> temp;
            while(x>0)
            {
                if(x&1)
                {
                    temp.push_back(nums[c]);
                }
                x=x>>1;
                c++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};