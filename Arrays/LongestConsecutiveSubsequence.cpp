using namespace std;
#include<bits/stdc++.h>
int findLongestConseqSubseq(int arr[], int N)
{
  //Your code here
  int freq[100005];
  memset(freq,0,sizeof(freq));
  for(int i=0;i<N;i++)
  {
      freq[arr[i]]++;
  }
  int maxi=0;
  int count=0;
  for(int i=0;i<=100005;i++)
  {
      if(freq[i]>0)
      {
          count++;
      }
      else
      {
          
          maxi=max(count,maxi);
          count=0;
      }
  }
  return maxi;
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
        long long int ans=findLongestConseqSubseq(arr,num);
        cout <<ans<< "\n";
    }
    return 0;
}