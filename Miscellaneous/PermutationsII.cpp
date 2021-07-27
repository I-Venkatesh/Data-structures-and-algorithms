class Solution {
public:
    map<vector<int>,bool> mp;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            int size=1;
            for(int x=1;x<=nums.size();x++)
            {
                size=size*x;
            }
            for(int x=1;x<=size;x++)
            {
                int i=nums.size()-2;
                while(i>=0&&nums[i]>=nums[i+1])
                {
                    i--;
                }
                if(i!=-1)
                {
                    int j=nums.size()-1;
                    while(nums[j]<=nums[i]&&j>i)
                    {
                        j--;
                    }
                    swap(nums[i],nums[j]);
                }
                i++;
                int j=nums.size()-1;
                while(i<j)
                {
                    swap(nums[i],nums[j]);
                    i++;
                    j--;
                }
                if(mp[nums]==0)
                {
                    mp[nums]=1;
                    ans.push_back(nums);
                }
                
            }
            return ans;
    }
};



// 12345
// 12354
// 12534
// 15234
