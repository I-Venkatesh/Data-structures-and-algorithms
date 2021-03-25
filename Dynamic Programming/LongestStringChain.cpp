class Solution {
public:
    map<string,int> mp;
    map<pair<string,string>,int> yes;
    int check(string s,string t)
    {
        if(t.length()-s.length()!=1)
        {
            return false;
        }
        if(yes[{s,t}]==1)
        {
            return true;
        }
        if(yes[{s,t}]==-1)
        {
            return false;
        }
        for(int i=0;i<t.length();i++)
        {
            string temp="";
            for(int j=0;j<t.length();j++)
            {
                if(j!=i)
                {
                    temp+=t[j];
                }
                else{
                    continue;
                }
            }
            if(s==temp)
            {
                yes[{s,t}]=1;
                return true;
            }
        }
        yes[{s,t}]=-1;
        return false;
    }
    int recur(string s,vector<string>& words)
    {
        if(mp[s])
        {
            return mp[s];
        }
        int depth=0,depth2=0;
        for(int i=0;i<words.size();i++)
        {
            if(words[i].length()-s.length()==1)
            {
                if(check(s,words[i]))
                {
                    depth=1+recur(words[i],words);
                }
            }
            depth2=max(depth2,depth);
        }
        return mp[s]=depth2;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end());
        for(int i=0;i<words.size();i++)
        {
            if(mp[words[i]]==false)
            {
                int c=recur(words[i],words);
                mp[words[i]]=c;
            }
        }
        int ans=0;
        for(auto i:mp)
        {
            // cout<<i.first<<" "<<i.second<<"\n";
            ans=max(ans,i.second);
        }
        return ans+1;
    }
};