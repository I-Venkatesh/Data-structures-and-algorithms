#include <iostream>
using namespace std;

int main() {
	int test;
	cin>>test;
	while(test--)
	{
	    int a,b,c;
	    cin>>a>>b>>c;
	    string s1,s2,s3;
	    cin>>s1>>s2>>s3;
	    int dp[a+1][b+1][c+1];
	    for(int i=0;i<=a;i++)
	    {
	        for(int j=0;j<=b;j++)
	        {
	            for(int k=0;k<=c;k++)
	            {
	                if(i==0||j==0||k==0)
	                {
	                    dp[i][j][k]=0;
	                }
	                else if(s1[i-1]==s2[j-1]&&s2[j-1]==s3[k-1])
	                {
	                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
	                }
	                else
	                {
	                    dp[i][j][k]=max(max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1]);
	                }
	                
	            }
	        }
	    }
	    cout<<dp[a][b][c]<<"\n";
	    
	}
	return 0;
}