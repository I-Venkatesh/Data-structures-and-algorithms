class Solution {
public:
    int minFlips(string s) {
        int zero=1,flip=0;
       for(int i=0;i<s.length();i++)
       {
            if(zero&&s[i]=='1')
            {
                flip++;
                zero=0;
            }
            else if(zero==0&&s[i]=='0')
            {
                flip++;
                zero=1;
            }
       }
       return flip;
    }
};