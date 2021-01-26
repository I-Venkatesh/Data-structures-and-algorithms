using namespace std;
#include<bits/stdc++.h>
class My_stack{
    public:
        int arr[100005];
        int num=0;
        void push(int val)
        {
            arr[num]=val;
            num++;
        }
        void top()
        {
            cout<<arr[num-1]<<"\n";
        }
        void pop()
        {
            num--;
        }
};
int main()
{
    My_stack st;
    st.push(20);
    st.push(30);
    st.top();
    st.pop();
    st.top();
}