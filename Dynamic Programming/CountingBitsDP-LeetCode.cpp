class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1;i<=num;i++)
        {
            if(i&1)
            {
                ans.push_back(1+ans[floor(i/2)]);
            }
            else{
                ans.push_back(ans[floor(i/2)]);
            }
        }
        return ans;
    }
};