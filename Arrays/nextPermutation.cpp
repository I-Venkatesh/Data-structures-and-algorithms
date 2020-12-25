#include <bits/stdc++.h>
using namespace std;
void nextPermutation(int arr[],int  num)
{
    int i=num-2;
    while(arr[i]>=arr[i+1]&&i>=0)
    {
        i--;
    }
    int j=num-1;
    while(arr[j]<=arr[i]&&j>i)
    {
        j--;
    }
    swap(arr[i],arr[j]);
    i++;
    j=num-1;
    while(i<j)
    {
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    //code
    int test;
    test = 1;
    while (test--)
    {
        int num;
        cin >> num;
        int arr[num];
        for (int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
        nextPermutation(arr,num);
    }
    return 0;
}