class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows==1)
        {
            vector<int> temp;
            temp.push_back(1);
            ans.push_back(temp);
            return ans;
        }
        if(numRows==2)
        {
            vector<int> temp;
            temp.push_back(1);
            ans.push_back(temp);
            temp.clear();
            temp.push_back(1);
            temp.push_back(1);
            ans.push_back(temp);
            return ans;
        }
        else{
            vector<int> temp;
                temp.push_back(1);
                ans.push_back(temp);
                temp.clear();
                temp.push_back(1);
                temp.push_back(1);
                ans.push_back(temp);
                temp.clear();
            for(int i=2;i<numRows;i++)
            {
                temp.clear();
                temp.push_back(1);
                for(int j=1;j<i;j++)
                {
                    temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
                temp.push_back(1);
                ans.push_back(temp);
    
            }
        }
        return ans;
    }
};