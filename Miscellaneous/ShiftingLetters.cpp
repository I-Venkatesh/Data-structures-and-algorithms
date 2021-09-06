class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int prefix[s.size()];
        prefix[shifts.size()-1]=shifts[shifts.size()-1];
        for(int i=shifts.size()-2;i>=0;i--)
        {
            prefix[i]=(prefix[i+1]+shifts[i])%26;
        }
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            ans+=char(((s[i]+(prefix[i])%26)-'a')%26)+'a';
        }
        return ans;
    }
};