class Solution {
public:
    vector<vector<int>> ans;
    map<vector<int>,bool> check;
    void calc(vector<int>& candidates, int target,int curr,vector<int>& temp)
    {
        if(target==0)
        {
            vector<int> temp2;
            for(auto i:temp)
            {
                temp2.push_back(i);
            }
            sort(temp2.begin(),temp2.end());
            if(!check[temp2])
            {
                ans.push_back(temp2);
                check[temp2]=true;
            }
            return;
        }
        if(target<0||curr>=candidates.size())
        {
            return;
        }
        if(candidates[curr]<=target)
        {
            calc(candidates,target,curr+1,temp);
            temp.push_back(candidates[curr]);
            calc(candidates,target-candidates[curr],curr+1,temp);
            temp.pop_back();
        }
        else{
            calc(candidates,target,curr+1,temp);
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        calc(candidates,target,0,temp);
        return ans;
    }
};
