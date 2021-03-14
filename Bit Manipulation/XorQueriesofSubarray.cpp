class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix;
        prefix.push_back(arr[0]);
        for(int i=1;i<arr.size();i++)
        {
            prefix.push_back(prefix[i-1]^arr[i]);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            int x=queries[i][0];
            int y=queries[i][1];
            if(x==0)
            {
                 ans.push_back(prefix[y]);
            }
            else{
                 ans.push_back(prefix[y]^prefix[x-1]);
            }
           
        }
        return ans;
    }
};