using namespace std;
#include <bits/stdc++.h>
int multiply(int x,int res[],int resSize)
{
    int carry=0;
    for(int i=0;i<resSize;i++)
    {
        int prod=res[i]*x+carry;
        res[i]=prod%10;
        carry=prod/10;
    }
    while(carry)
    {
        res[resSize]=carry%10;
        carry/=10;
        resSize++;
    }
    return resSize;
}
int factorial(int num)
{
    int res[100000];
    res[0]=1;
    int resSize=1;
    for(int i=2;i<=num;i++)
    {
        resSize=multiply(i,res,resSize);
    }
    for(int i=resSize-1;i>=0;i--)
    {
        cout<<res[i];
    }
}
int main() {
	//code
	int test;
	cin>>test;
	while(test--)
	{
    	int num;
    	cin>>num;
        factorial(num);
        cout<<"\n";
	}
	return 0;
}