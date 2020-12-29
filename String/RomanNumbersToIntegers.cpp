using namespace std;
#include <bits/stdc++.h>
int main()
{
    string str;
    cin>>str;
    int sum=0,diff=0;
    map<char,int> arr;
    arr['I']=1;
    arr['V']=5;
    arr['X']=10;
    arr['L']=50;
    arr['C']=100;
    arr['D']=500;
    arr['M']=1000;
    if(str.size()==1)
    {
        cout<<arr[str[0]]<<"\n";
    }
    
    for(int i=0;i<str.length()-1;i++)
    {
        if(arr[str[i]]>=arr[str[i+1]])
        {
            sum+=arr[str[i]];
        }
        else{
            sum-=arr[str[i]];
        }
    }
    sum+=arr[str[str.length()-1]];
    cout<<sum<<"\n";
}