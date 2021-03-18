class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int known[N+1];
        memset(known,0,sizeof(known));
        for(auto i:trust)
        {
            known[i[1]]++;
        }
        for(int i=1;i<=N;i++)
        {
            if(known[i]==N-1)
            {
                for(auto j:trust)
                {
                    if(j[0]==i)
                    {
                        return -1;
                    }
                }
                return i;
            }
        }
        return -1;
    }
};