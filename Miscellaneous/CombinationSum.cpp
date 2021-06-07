class Solution {
public:
    void help(vector<vector<int>> &ans,vector<int> &candidates, int target, int index,vector<int> collect)
    {
        if(target==0)
        {
            ans.push_back(collect);
            return;
        }
        
        for(int i=index;i<candidates.size();i++)
        {
            if(target-candidates[i]>=0)
            {
                collect.push_back(candidates[i]);
                help(ans,candidates,target-candidates[i],i,collect);
                collect.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        help(ans,candidates,target,0,temp);
        return ans;
    }
};