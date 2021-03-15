class Solution {
public:
    bool hasAllCodes(string s, int k) {
        map<string,bool> mp;
        string hold;
        int len=s.length() < k ? s.length():k;
        for(int i=0;i<len;i++)
        {
            hold+=s[i];
        }
        mp[hold]=true;
        for(int i=k;i<s.length();i++)
        {
            hold+=s[i];
            hold=hold.substr(1);
            mp[hold]=true;
        }
        return (mp.size()==(1<<k));
    }
};