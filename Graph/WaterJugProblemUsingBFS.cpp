#include<bits/stdc++.h>
using namespace std;
int visited[100005];
int main()
{
    int n,m,target;
    n=4;
    m=3;
    target=2;
    queue<pair<int,int>> q;
    vector<pair<int,int>> path;
    q.push({0,0});
    map<pair<int,int>,int> mp;
      bool ok=false;
    while(!q.empty())
    {
        pair<int,int> j=q.front();
        q.pop();
        pair<int,int> x;
        if(mp[{j.first,j.second}]==1)
        {
            continue;
        }
        if(j.first>n||j.second>m||j.first<0||j.second<0)
        {
            continue;
        }
        path.push_back({j.first,j.second});
      
        mp[{j.first,j.second}]=1;
        if(j.first==target||j.second==target)
        {
            ok=true;
        if(j.first==target){
            if(j.second!=0)
            {
                path.push_back({j.first,0});
            }

        }
        else{
            if(j.first!=0)
            {
                path.push_back({0,j.second});
            }
        }
        int sz=path.size();
            for (int i = 0; i < sz; i++)
                cout << "(" << path[i].first
                    << ", " << path[i].second << ")\n";
            break;
        }
        q.push({ j.first, m}); 
        q.push({ n, j.second }); 
         for (int ap = 0; ap <= max(n, m); ap++) {
            int c = j.first + ap;
            int d = j.second - ap;
            if (c == n || (d == 0 && d >= 0))
                q.push({ c, d });

            c = j.first - ap;
            d = j.second + ap;
 

            if ((c == 0 && c >= 0) || d == m)
                q.push({ c, d });
        }
 
        q.push({ n, 0 }); 
        q.push({ 0, m });
    }
     if(ok)
    {
        cout<<"YES"<<"\n";
    }
    else
    {        
        cout<<"NO"<<"\n";
    }   
}