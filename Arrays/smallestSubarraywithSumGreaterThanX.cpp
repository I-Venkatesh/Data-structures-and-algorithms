#include <iostream>
using namespace std;

int main() {
	//code
	int test;
	cin>>test;
	while(test--)
	{
	    int num,x;
	    cin>>num>>x;
	    int arr[num];
	    for(int i=0;i<num;i++)
	    {
	        cin>>arr[i];
	    }
	    int j=0,i=0;
	    long long int sum=0;
	    int mini=100000;
	    while(i<num&&j<num)
	    {
	        while(sum<=x&&j<num)
	        {
	            sum+=arr[j];
	            j++;
	        }
	        mini=min(mini,j-i+1);
	        while(sum>x&&i<num)
	        {
	            sum-=arr[i];
	            i++;
	        }
	        mini=min(mini,j-i+1);
	    }
	    cout<<mini<<"\n";
	}
	return 0;
}