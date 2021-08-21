class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                st.push('(');
            }
            else{
                if(st.empty())
                {
                    ans++;
                }
                else
                {
                    if(st.top()=='(')
                    {
                        st.pop();
                    }
                    else{
                        ans++;
                    }
                }
            }
        }
        ans+=st.size();
        return ans;
    }
};