#include<bits/stdc++.h>
using namespace std;
bool ispar(string s)
{
    // Your code here
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        {
            st.push(s[i]);
        }
        else
        {
            if(!st.empty())
            {
                if(s[i]==']'&&st.top()!='[')
                {
                    return false;
                }
                else if(s[i]==')'&&st.top()!='(')
                {
                    return false;
                }
                else if(s[i]=='}'&&st.top()!='{')
                {
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else
            {
                return false;
            }
        }
    }
    if(!st.empty())
    {
        return false;
    }
    else{
        return true;
    }
}
int main()
{
    string s;
    cin>>s;
    cout<<ispar(s)<<"\n";
}
