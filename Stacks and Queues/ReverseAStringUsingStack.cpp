#include<bits/stdc++.h>
using namespace std;
string reverse(string S, int len)
{
    stack<char> st;
    for(int i=0;i<len;i++)
    {
        st.push(S[i]);
    }
    int index=0;
    while(!st.empty())
    {
        S[index]=st.top();
        index++;
        st.pop();
    }
    return S;
}
int main()
{
    string s;
    cin>>s;
    cout<<reverse(s,s.size())<<"\n";
}
