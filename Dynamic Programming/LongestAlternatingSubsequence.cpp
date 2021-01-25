#include<bits/stdc++.h>
using namespace std;
int AlternatingaMaxLength(vector<int> &nums)
{
    // Code here
    int dec = 1, inc = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
        {
            inc = dec + 1;
        }
        else if (nums[i] < nums[i - 1])
        {
            dec = inc + 1;
        }
    }
    return max(inc, dec);
}
int main()
{
    int num;
    cin>>num;
    vector<int> arr(num);
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    cout<<AlternatingaMaxLength(arr)<<"\n";
}