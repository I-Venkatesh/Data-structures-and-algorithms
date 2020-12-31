#include <iostream>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int n,target;
	    cin>>n>>target;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int i=-1,j=-1;
	    bool ok=false;
	    while(j<n&&i<n)
	    {
	        if(arr[j]==target)
	        {
	            i=j;
	            while(i<n&&arr[i]==target)
	            {
	                i++;
	            }
	            i--;
	        }
	        else{
	            j++;
	        }
	        if(i!=-1&&j!=-1)
	        {
	            ok=true;
	            cout<<j<<" "<<i<<"\n";
	            break;
	        }
	    }
	    if(!ok)
	    {
	        cout<<-1<<"\n";
	    }
	    
	}
	return 0;
}