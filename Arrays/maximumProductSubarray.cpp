using namespace std;
#include<bits/stdc++.h>
long long maxProduct(int *arr, int n)
{
    // code here
    long long int arr1[n];
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr[i];
    }
    long long int minVal = 1;
    long long int maxVal = 1;
    long long int maxProduct = 1;

    for (int i = 0; i < n; i++)
    {

        if (arr1[i] < 0)
            swap(maxVal, minVal);

        maxVal = max(arr1[i], maxVal * arr1[i]);
        minVal = min(arr1[i], minVal * arr1[i]);
        maxProduct = max(maxProduct, maxVal);
    }
    return maxProduct;
}
int main()
{
    //code
    int test;
    cin >> test;
    while (test--)
    {
        int num;
        cin >> num;
        int arr[num];
        for(int i=0;i<num;i++)
        {
            cin>>arr[i];
        }
        long long int ans=maxProduct(arr,num);
        cout <<ans<< "\n";
    }
    return 0;
}