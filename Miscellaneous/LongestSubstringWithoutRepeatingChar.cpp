class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
        {
            return 0;
        }
        int freq[130];
        memset(freq,0,sizeof(freq));
        int i=0,j=0,ans=1;
        while(j<s.length())
        {
            if(freq[s[j]]>0)
            {
                freq[s[i]]--;
                i++;
            }
            else{
                freq[s[j]]++;
                j++;
                ans=max(ans,j-i);
            }
        }
        return ans;
    }
};