class Solution {
public:
    int calc(vector<string>& words, int freq[26] , vector<int>& score,int curr)
    {
        int temp[26];
        for(int i=0;i<26;i++)
        {
            temp[i]=freq[i];
        }
        if(curr==words.size())
        {
            return 0;
        }
        int ans=0;
        for(int i=0;i<words[curr].size();i++)
        {
            if(freq[words[curr][i]-'a']>0)
            {
                ans+=score[words[curr][i]-'a'];
                freq[words[curr][i]-'a']--;
            }
            else
            {
                ans=INT_MIN;
            }
        }
        return max(ans+calc(words,freq,score,curr+1),calc(words,temp,score,curr+1));
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int freq[26];
        int maxi=0;
        memset(freq,0,sizeof(freq));
        for(auto i:letters)
        {
            freq[i-'a']++;
        }
        return calc(words,freq,score,0);
    }
};