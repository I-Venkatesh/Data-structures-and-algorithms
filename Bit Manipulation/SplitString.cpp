class Solution {
public:
    int numSplits(string s) {
        int freq1[30];
        int freq2[30];
        memset(freq1,0,sizeof(freq1));
        memset(freq2,0,sizeof(freq2));
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            freq2[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++)
        {
            int x=0,y=0;
            bool ok=true;
            freq1[s[i]-'a']++;
            freq2[s[i]-'a']--;
            for(int j=0;j<27;j++)
            {
                if(freq1[j]>0)
                {
                    x++;
                }
                if(freq2[j]>0)
                {
                    y++;
                }
            }
            if(x==y)
            {
                count++;
            }
        }
        return count;
    }
};