class Solution {
public:
    int maxProduct(vector<string>& words) {
        int val[100005];
        memset(val,0,sizeof(val));
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                val[i]|=(1<<(words[i][j]-'a'));
            }
        }
        int ans=0;
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if(!(val[i]&val[j])&&(ans<words[i].length()*words[j].length()))
                {
                    ans=words[i].length()*words[j].length();
                }
            }
        }
        return ans;
    }
};