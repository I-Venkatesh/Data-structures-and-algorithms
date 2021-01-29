#include <bits/stdc++.h>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i=0;i<num;i++)
        {
            cin>>arr[i];
        }
        int k;
        cin>>k;
        queue<int> q;
        for(int i=0;i<k;i++)
        {
            if(arr[i]<0)
            {
                q.push(arr[i]);
            }
        }
        int res=0;
        for(int i=k;i<=num-1;i++)
        {
            if(q.size() != 0)
	            cout<<q.front()<<" ";
	        else cout<<"0 ";
	        if(arr[i-k] < 0) q.pop();
	        if(arr[i] < 0) q.push(arr[i]);
	  }
	   if(q.size() != 0)
	      cout<<q.front()<<" ";
	      else cout<<"0 ";
	  cout<<"\n";
	}
	return 0;
}