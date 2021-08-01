class Solution{
public:
    int approach1(String S)
    {
        int open=0,close=0,maxi=0;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='(')
            {
                open++;
            }
            else if(S[i]==')')
            {
                close++;
            }
            if(open==close)
            {
                maxi=max(maxi,open+close);
            }
            else if(close>open){
                open=0;
                close=0;
            }
        }
        open=0;
        close=0;
        for(int i=S.length()-1;i>=0;i--)
        {
            if(S[i]=='(')
            {
                open++;
            }
            else if(S[i]==')')
            {
                close++;
            }
            if(open==close)
            {
                maxi=max(maxi,open+close);
            }
            else if(close<open){
                open=0;
                close=0;
            }
        }
        return maxi;
    }
    int maxLength(string S){
        stack<int> st;
        st.push(-1);
        int maxi=0;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='(')
            {
                st.push(i);
            }
            else{
                if(st.empty())
                {
                    st.push(i);
                }
                else{
                    st.pop();
                    if(!st.empty())
                    {
                        maxi=max(maxi,i-st.top());
                    }
                    else{
                        st.push(i);
                    }
                }
            }
        }
        return maxi;
    }
};