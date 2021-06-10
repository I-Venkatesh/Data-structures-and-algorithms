class Solution {
public:
    map<char,string> mp;
    vector<string> ans;
    void calc(string dig,int index,string s)
    {
        if(index==dig.size())
        {
            ans.push_back(s);
        }
        for(int i=0;i<mp[dig[index]].size();i++)
        {
            calc(dig,index+1,s+mp[dig[index]][i]);
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
        {
            return ans;
        }
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        calc(digits,0,"");
        return ans;
    }
};