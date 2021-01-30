using namespace std;
#include<bits/stdc++.h>
int largest(int num)
{
    int x=0;
    while((1<<x)<=num){
        x++;
    }
    return x-1;
}
int countBits(int num)
{
    if(num==0)
    {
        return 0;
    }
    int x=largest(num);
    int till=x*(1<<(x-1));
    int b1=num-(1<<x)+1;
    int rest=num-(1<<x);
    int ans=till+b1+countBits(rest);
    return ans;
}
int main()
{
    int num;
    cin>>num;
    cout<<countBits(num);
}