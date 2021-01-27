using namespace std;
#include<bits/stdc++.h>
int evaluatePostfix(string S)
{
    stack<int> st;
    for(int i=0;i<S.size();i++)
    {
        if(S[i]!='*'&&S[i]!='+'&&S[i]!='-'&&S[i]!='/')
        {
            st.push(S[i]-'0');
        }
        else{
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            int z=0;
            if(S[i]=='+')
            {
                z=x+y;
            }
            else if(S[i]=='/')
            {
                z=y/x;
            }
            else if(S[i]=='*'){
                z=x*y;
            }
            else{
                z=y-x;
            }
            st.push(z);
        }
    }
    return st.top();
}
int main()
{
    string s;
    cin>>s;
    cout<<evaluatePostfix(s)<<"\n";
}