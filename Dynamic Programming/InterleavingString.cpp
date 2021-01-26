using namespace std;
#include<bits/stdc++.h>
unordered_map<string, bool> mp;
bool solve(string fs,string ss,string is)
{
    if(fs.empty()&&ss.empty()&&is.empty())
    {
        return 1;
    }
    if(is.empty())
    {
        return 0;
    }
    string str=fs+"|"+ss+"|"+is;
    if(mp.count(str))
    {
        return mp[str];
    }
    bool first=(!fs.empty()&&fs[0]==is[0]&&solve(fs.substr(1),ss,is.substr(1)));
    bool second(!ss.empty()&&ss[0]==is[0]&&solve(fs,ss.substr(1),is.substr(1)));
    return mp[str]=first || second;
}
int main()
{
    string fs,ss,is;
    cin>>fs>>ss>>is;
    cout<<solve(fs,ss,is);
}