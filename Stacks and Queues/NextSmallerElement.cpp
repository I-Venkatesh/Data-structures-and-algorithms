using namespace std;
#include<bits/stdc++.h>
int main()
{
    int num;
    cin>>num;
    int arr[num];
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    stack<int> st;
    st.push(arr[0]);
    for(int i=1;i<num;i++)
    {
        if(st.empty())
        {
            st.push(arr[i]);
            continue;
        }
        while(st.empty()==false&&st.top()>arr[i])
        {
            cout<<st.top()<<" "<<arr[i]<<"\n";
            st.pop();
        }
        st.push(arr[i]);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" "<<-1<<"\n";
        st.pop();
    }
}