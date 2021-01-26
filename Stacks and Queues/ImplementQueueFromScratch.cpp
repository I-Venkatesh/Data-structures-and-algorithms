using namespace std;
#include<bits/stdc++.h>
class My_queue{
    public:
        int arr[100005];
        int num=0;
        void push(int val)
        {
            if(num==0)
            {
                arr[num]=val;
                num++;
            }
            else{
                for(int i=num-1;i>=0;i--)
                {
                    arr[i+1]=arr[i];
                }
                arr[0]=val;
                num++;
            }
        }
        void top()
        {
            cout<<arr[num-1]<<"\n";
        }
        void pop()
        {
            // arr[num]=0;
            num--;
        }
};
int main()
{
    My_queue st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.top();
    st.pop();
    st.top();
}