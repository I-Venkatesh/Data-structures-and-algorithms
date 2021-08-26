class Solution {
public:
    map<string,bool> dp;
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()==0&&s2.length()==0&&s3.length()!=0)
        {
            return 0;
        }
        if(s1.length()==0&&s2.length()==0&&s3.length()==0)
        {
            return 1;
        }
        if(dp.count(s1+"|"+s2+"|"+s3))
        {
            return dp.count(s1+s2+s3);
        }
        bool ok1=false,ok2=false;
        if(s1[0]==s3[0])
        {
            ok1=!s1.empty()&&isInterleave(s1.substr(1),s2,s3.substr(1));
        }
        if(s2[0]==s3[0])
        {
            ok2=!s2.empty()&&isInterleave(s1,s2.substr(1),s3.substr(1));
        }
        return dp[s1+"|"+s2+"|"+s3]=ok1||ok2;
    }
};