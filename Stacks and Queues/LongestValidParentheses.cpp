using namespace std;
#include<bits/stdc++.h>
int findMaxLen(string s)
{
    stack<int> st;
    st.push(-1);
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (!st.empty())
            {
                res = max(res, i - st.top());
            }
            else
            {
                st.push(i);
            }
        }
    }
    return res;
}
int main()
{
    string s;
    cin>>s;
    cout<<findMaxLen(s)<<"\n";
}