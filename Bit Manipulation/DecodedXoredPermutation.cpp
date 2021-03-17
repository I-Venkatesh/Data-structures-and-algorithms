class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int x=0;
        for(int i=1;i<=encoded.size()+1;i++)
        {
            x=x^i;
        }
        int first=0,tot=0;
        for(int i=0;i<encoded.size();i++)
        {
            tot=tot^encoded[i];
            first=first^tot;
        }
        first=first^x;
        vector<int> ans;
        ans.push_back(first);
        for(int i=0;i<encoded.size();i++)
        {
            ans.push_back(ans[i]^encoded[i]);
        }
        return ans;
    }
};

   