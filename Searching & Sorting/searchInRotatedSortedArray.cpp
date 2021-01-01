#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num,target;
    cin >> num>>target;
    int arr[num];
    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    int diff=0,diffpos=0,i=0,j=num-1;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(arr[mid]>=arr[j])
        {
            if(arr[mid]>diff)
            {
                diff=arr[mid];
                diffpos=mid;
            }
            i=mid+1;
        }
        else{
            j=mid;
        }
    }
             int lefty=-1,righty=-1,r1=diffpos,l1=diffpos+1;
        int l=0,r=num-1;
        while(l<=r1)
        {
            int mid=l+((r1-l)/2);
            if(arr[mid]==target)
            {
                lefty=mid;
                break;
            }
            else if(arr[mid]>target)
            {
                r1=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        while(l1<=r)
        {
            int mid=l1+((r-l1)/2);
            if(arr[mid]==target)
            {
                righty=mid;
                break;
            }
            else if(arr[mid]>target)
            {
                r=mid-1;
            }
            else
            {
                l1=mid+1;
            }
        }
        if(lefty==-1&&righty==-1)
        {
            cout<<-1;
        }
        else if(lefty!=-1)
        {
            cout<<lefty;
        }
        else
        {
            cout<<righty;
        }
    
    return 0;
}