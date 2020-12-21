using namespace std;
#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define INFINITE 1e9 + 5
#define MOD 1000000007
#define MAXN 100001 
#define pll pair<ll,ll>
#define pii pair<int,int>
#define debugArray(arr) cout << #arr<<" : "<<endl;for(int i : arr){cout << i <<", ";} cout <<endl;
#define debugVariable(x) cout <<#x<<"="<<x<<"\n";
#define check(x) cout<<"CHECK="<<#x<<"\n";
priority_queue<int, vector<int>, greater<int>> pq; //increasing priority queue
int X[4]={1,0,-1,0};
int Y[4]={0,1,0,-1};
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
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
        for(int i=0;i<num/2;i++)
        {
            swap(arr[i],arr[num-1-i]);
        }
        for(auto i:arr)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
}