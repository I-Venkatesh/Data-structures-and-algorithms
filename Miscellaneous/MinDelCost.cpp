class Solution {
public:
    int minCost(string s, vector<int>& cost) {
       int i=0,j=1,ans=0,sum=0;
        int maxi=INT_MIN;
        bool ok=false;
       while(j<s.length())
       {
           if(s[i]==s[j])
           {
               ok=true;
               maxi=INT_MIN;
               maxi=max(maxi,cost[i]);
               sum=cost[i];
               while(j<s.length()&&s[i]==s[j])
               {
                   sum+=cost[j];
                   maxi=max(cost[j],maxi);
                   j++;
               }
               // cout<<mini<<"\n";
               ans+=sum-maxi;
               i=j-1;
               ok=false;
           }
           else
           {
               ok=false;
               i++;
               j++;
           }
       }
        if(ok)
        {
            ans+=sum-maxi;
        }
    return ans;
    }
};