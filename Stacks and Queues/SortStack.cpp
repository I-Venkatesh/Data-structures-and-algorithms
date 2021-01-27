using namespace std;
#include<bits/stdc++.h>
stack<int> st;
void sorting(int num)
{
    if(st.empty()||num>st.top())
    {
        st.push(num);
    }
    else{
        int temp=st.top();
        st.pop();
        sorting(num);
        st.push(temp);
    }
}
void sortStack()
{
    if(st.empty())
    {
        return;
    }
    int temp=st.top();
    st.pop();
    sortStack();
    sorting(temp);
}
int main()
{
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int x;
        cin>>x;
        st.push(x);
    }
    sortStack();
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}