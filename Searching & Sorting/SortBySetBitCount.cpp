#include <bits/stdc++.h>
using namespace std;
static int countBits(int n)
{
    return __builtin_popcount(n);
}
static int cmp(int a, int b)
{
    int count1 = countBits(a);
    int count2 = countBits(b);
    if (count1 <= count2)
        return false;
    return true;
}

void sortBySetBitCount(int arr[], int n)
{
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
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
        sortBySetBitCount(arr, num);
    }
    return 0;
}