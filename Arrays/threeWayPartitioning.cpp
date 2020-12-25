#include <bits/stdc++.h>
using namespace std;
void threeWayPartition(vector<int> &array, int a, int b)
{
    // code here
    int low, mid, high;
    low = 0, mid = 0, high = array.size() - 1;
    while (mid <= high)
    {
        if (array[mid] < a)
        {
            swap(array[mid], array[low]);
            mid++;
            low++;
        }
        else if (array[mid] > b)
        {
            swap(array[mid], array[high]);
            high--;
        }
        else
        {
            mid++;
        }
    }
    for(auto i:array)
    {
        cout<<i<<"\n";
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
        vector<int> arr(num);
        for (int i = 0; i < num; i++)
        {
            cin >> arr[i];
        }
        int a,b;
        cin>>a>>b;
        threeWayPartition(arr,a,b);
        // cout<<pal("20");
    }
    return 0;
}