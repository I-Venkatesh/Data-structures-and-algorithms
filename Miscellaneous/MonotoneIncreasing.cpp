class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips=0,ones=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                ones++;
            }
            else{
                flips=min(flips+1,ones);
            }
        }
        return flips;
    }
};