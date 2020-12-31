#include <bits/stdc++.h>
using namespace std;
int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
int main() {
	//code
	int test;
	cin>>test;
	while(test--)
	{
	    int r,c;
	    cin>>r>>c;
	    char arr[r+1][c+1];
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    string word;
	    cin>>word;
	    bool ok=false;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int row=i;
                int col=j;
                if(arr[row][col]!=word[0])
                {
                    continue;
                }
                else{
                    int len=word.length();
                    for(int dir=0;dir<8;dir++)
                    {
                        int k,rd=row+x[dir],cd=col+y[dir];
                        for(k=1;k<len;k++)
                        {
                            if(rd>=r||rd<0||cd>=c||cd<0)
                            {
                                break;
                            }
                            if(arr[rd][cd]!=word[k])
                            {
                                break;
                            }
                            rd+=x[dir];
                            cd+=y[dir];
                        }
                        if(k==len)
                        {
                            ok=true;
                            cout<<i<<" "<<j<<", ";
                            break;
                        }
                    }
                }
            }
        }
        if(!ok)
        {
            cout<<-1<<"\n";
        }
        else{
            cout<<"\n";
        }
	}
	return 0;
}

