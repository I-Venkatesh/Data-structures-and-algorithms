using namespace std;
#include<bits/stdc++.h>
int main() {
	int test;
	test=1;
	while(test--)
	{
	    int n,k;
    	cin>>k>>n;
        int arr[n];
    	for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        // code here
        vector<pair<int,int>> all;
        for(int i=0;i<n;i++)
        {
            if(arr[i]-k>=0)
            {
                all.push_back({arr[i]-k,i});
            }
            all.push_back({arr[i]+k,i});
        }
        sort(all.begin(),all.end());
        int left=0;
        int right=0;
        int ele=0;
        int visited[n];
        memset(visited,0,sizeof(visited));
        while(ele<n&&right<all.size())
        {
            if(visited[all[right].second]==0)
            {
                ele++;
            }
            visited[all[right].second]++;
            right++;
        }
        int ans=all[right-1].first-all[left].first;
        while(right<all.size())
        {
            if(visited[all[left].second]==1)
            {
                ele--;
            }
            visited[all[left].second]--;
            left++;
            while(ele<n&&right<all.size())
            {
                if(visited[all[right].second]==0)
                {
                    ele++;
                }
                visited[all[right].second]++;
                right++;
            }
            if(ele==n)
            {
                ans=min(ans,all[right-1].first-all[left].first);
            }
            else
            {
                break;
            }
        }
        cout<<ans<<"\n";
	}
	return 0;
}