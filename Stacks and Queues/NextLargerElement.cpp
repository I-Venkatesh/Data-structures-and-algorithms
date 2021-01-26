using namespace std;
#include<bits/stdc++.h>
vector<long long> nextLargerElement(vector<long long> arr, int n){
    stack<long long> st;
    map<long long,long long> ans;
    for(int i=0;i<n;i++)
    {
        if(st.empty())
        {
            st.push(arr[i]);
        }
        else
        {
            while(st.empty()==false&&st.top()<arr[i])
            {
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(arr[i]);
        }
    }
    while(!st.empty())
    {
        ans[st.top()]=-1;
        st.pop();
    }
    vector<long long> ret(n);
    for(int i=0;i<n;i++)
    {
        if(ans[arr[i]]==0)
        {
            ret[i]=-1;
        }
        else
        {
            ret[i]=ans[arr[i]];
        }
    }
    return ret;
}
int main()
{
    int num;
    cin>>num;
    vector<long long> arr;
    for(int i=0;i<num;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<long long> ans=nextLargerElement(arr,4);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}