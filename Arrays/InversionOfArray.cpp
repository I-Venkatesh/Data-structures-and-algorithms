using namespace std;
#include<bits/stdc++.h>
long long int merge(long long int arr[],long long int temp[], long long int l,long long int mid,long long int r)
{
    long long int inv=0;
    long long int i=l;
    long long int j=mid;
    long long int k=l;
    while(i<=mid-1&&j<=r)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
            inv=inv+(mid-i);
        }
    }
    while(i<=mid-1)
    {
        temp[k++]=arr[i++];
    }
    while(j<=r)
    {
        temp[k++]=arr[j++];
    }
    for(long long int i=l;i<=r;i++)
    {
        arr[i]=temp[i];
    }
    return inv;
}
long long int mergeSort(long long int arr[],long long int temp[],long long int l,long long int r)
{
    long long int inv=0;
    if(r>l)
    {
        long long int mid=(r+l)/2;
        inv+=mergeSort(arr,temp,l,mid);
        inv+=mergeSort(arr,temp,mid+1,r);
        inv+=merge(arr,temp,l,mid+1,r);
    }
    return inv;
}
long long int mergeSort(long long int arr[],long long int N)
{
    long long int temp[N+1];
    return mergeSort(arr,temp,0,N-1);
}
long long int inversionCount(long long int arr[], long long N)
{
    // Your Code Here
    return mergeSort(arr,N);
} 
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int arr[n];
        for(long long int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<inversionCount(arr,n)<<"\n";
    }
}