class Solution {
public:
    vector<string> ans;
    void helper(string s,int left,int right,int n)
    {
        if(left==n&&right==n)
        {
            ans.push_back(s);
            return;
        }
        if(left<n)
        {
            helper(s+"(",left+1,right,n);
        }
        if(right<left&&right<n)
        {
            helper(s+")",left,right+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        helper("",0,0,n);
        return ans;
    }
};