class Solution {
public:
    vector<int> minOperations(string boxes) {
        int prefix[boxes.size()];
        int suffix[boxes.size()];
        memset(prefix,0,sizeof(prefix));
        memset(suffix,0,sizeof(suffix));
        int balls=boxes[0]-'0';
        for(int i=1;i<boxes.size();i++)
        {
            prefix[i]=prefix[i-1]+balls;
            balls+=boxes[i]-'0';
        }
        balls=boxes[boxes.size()-1]-'0';
        for(int i=boxes.size()-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]+balls;
            balls+=boxes[i]-'0';
        }
        vector<int> ans;
        for(int i=0;i<boxes.size();i++)
        {
            ans.push_back(prefix[i]+suffix[i]);
        }
        return ans;
    }
};