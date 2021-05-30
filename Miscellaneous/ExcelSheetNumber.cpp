class Solution {
public:
    int titleToNumber(string columnTitle) {
        reverse(columnTitle.begin(),columnTitle.end());
        long long int ans=0;
        for(int i=0;i<columnTitle.size();i++)
        {
            ans+=pow(26,i)*(columnTitle[i]-'A'+1);
        }
        return ans;
    }
};