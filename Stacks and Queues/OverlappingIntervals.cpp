using namespace std;
#include<bits/stdc++.h>
vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> vec, int n) {
    sort(vec.begin(),vec.end());
    stack<pair<int,int>> st;
    vector<pair<int,int>> ans;
    for(int i=vec.size()-1;i>=0;i--)
    {
        st.push(vec[i]);
    }
    while(!st.empty()&&st.size()!=1)
    {
        pair<int,int> a=st.top();
        pair<int,int> b={-1,-1};
        st.pop();
        if(st.empty()==false)
        {
            b=st.top();
            st.pop();
        }
        if(b.second!=-1&&a.second>=b.first)
        {
            pair<int,int> temp={a.first,max(a.second,b.second)};
            st.push(temp);
        }
        else{
            ans.push_back(a);
            st.push(b);
        }
    }
    if(st.size()==1)
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main()
{
    int num;
    cin>>num;
    vector<pair<int,int>> vec;
    for(int i=0;i<num;i++)
    {
        int x,y;
        cin>>x>>y;
        vec.push_back({x,y});
    }
    vec=overlappedInterval(vec,num);
    for(auto i:vec)
    {
        cout<<i.first<<" "<<i.second<<"\n";
    }
}