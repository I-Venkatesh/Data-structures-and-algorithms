class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string> ans;
        for(int i=1;i<(1<<(arr.size()));i++)
        {
            int x=i;
            int c=0;
            string s;
            while(x>0)
            {
                if(x&1)
                {
                    s+=arr[c];
                }
                c++;
                x=x>>1;
            }
            if(s.size()>0)
            {
                ans.push_back(s);
            }
        }
        int res=0;
        for(auto i:ans)
        {
            int freq[26];
            memset(freq,0,sizeof(freq));
            for(int j=0;j<i.length();j++)
            {
                freq[i[j]-'a']++;
            }
            bool ok=true;
            for(int j=0;j<26;j++)
            {
                if(freq[j]>1)
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                int x=i.size();
                res=max(res,x);
            }
        }
        return res;
    }
};