using namespace std;
#include <bits/stdc++.h>
int X[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int Y[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    int visited[1000][1000];
    bool valid(int x,int y,int n)
    {
        if(x>=1&&x<=n&&y>=1&&y<=n&&visited[x][y]==0)
        {
            return 1;
        }
        return 0;
    }
    int chess(int x1,int y1,int x2, int y2,int n)
    {
        queue<pair<pair<int,int>,int>> q;
        q.push({{x1,y1},0});
        visited[x1][y1]=1;
        while(!q.empty())
        {
            pair<pair<int,int>,int> p=q.front();
            int x=p.first.first;
            int y=p.first.second;
            int steps=p.second;
            if(x==x2&&y==y2)
            {
                return steps;
                
            }
            q.pop();
            for(int i=0;i<8;i++)
            {
                if(valid(x+X[i],y+Y[i],n))
                {
                    visited[x+X[i]][y+Y[i]]=1;
                    q.push({{x+X[i],y+Y[i]},steps+1});
                }
            }
        }
        return -1;
    }
        
	int minStepToReachTarget(int KnightPos[], int TargetPos[], int N){
	    // Code here
	    int x1=KnightPos[0];
	    int y1=KnightPos[1];
	    int x2=TargetPos[0];
	    int y2=TargetPos[1];
	    memset(visited,0,sizeof(visited));
	    return chess(x1,y1,x2,y2,N);
	}
int main()
{
    int starting[2]={4,5};
    int target[2]={1,1};
    cout<<minStepToReachTarget(starting,target,6)<<"\n";
}
