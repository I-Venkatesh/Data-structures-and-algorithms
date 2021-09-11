class Solution {
public:
    static bool comp(pair<int, string> &a,pair<int, string> &b)
    {
        if(a.first==b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        sort(words.begin(),words.end());
        map<string,int> mp;
        for(auto i:words)
        {
            mp[i]++;
        }
        vector<pair<int,string>> ans;
        for(auto i:mp)
        {
            ans.push_back({i.second,i.first});
        }
        
        sort(ans.begin(),ans.end(),comp);
        vector<string> g;
        for(int i=0;i<k;i++)
        {
            g.push_back(ans[i].second);
        }
        return g;
    }
};