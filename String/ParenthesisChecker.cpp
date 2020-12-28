#include <bits/stdc++.h>
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
int main() {
   int t,n,m,x,i,j,k,q;
   //cin >> t;
   t = 1;
   while(t--)
   {
        string s;
        cin>>s;
        if(ispar(s)){
            cout<<"Balanced"<<"\n";
        }
        else
        {
            cout<<"Not Balanced"<<"\n";
        }
   }
   return 0;
}