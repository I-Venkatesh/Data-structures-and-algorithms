class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos=s.find(part);
        if(pos==-1)
        {
            return s;
        }
        string next=s.substr(0,pos)+s.substr(pos+part.size());
        string ans=removeOccurrences(next,part);
        return ans;
    }
};