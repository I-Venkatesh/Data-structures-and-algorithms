class Solution {
public:
    string reorganizeString(string s) {
        int arr[26];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<s.length();i++)
        {
            arr[s[i]-'a']++;
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<26;i++)
        {
            if(arr[i]>0)
            {
                pq.push({arr[i],char(i+'a')});
            }
        }
        string ans="";
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            while(it.first>0)
            {
                if(pq.empty())
                {
                     while(it.first)
                    {
                        ans+=it.second;
                        it.first-=1;
                    }
                }
                else{
                    auto it2=pq.top();
                    pq.pop();
                    ans+=it.second;
                    ans+=it2.second;
                    it.first-=1;
                    it2.first-=1;
                    if(it2.first>0)
                    {
                        pq.push({it2.first,it2.second});
                    }
                    else if(pq.empty()&&it.first>0){
                         while(it.first)
                        {
                            ans+=it.second;
                            it.first-=1;
                        }
                    }
                }
            }
        }
        for(int i=1;i<ans.length();i++)
        {
            if(ans[i]==ans[i-1])
            {
                return "";
            }
        }
        return ans;
    }
};