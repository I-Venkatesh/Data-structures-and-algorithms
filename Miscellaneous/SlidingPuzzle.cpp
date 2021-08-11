class Solution {
public:
    string swapping(string curr,int i,int j)
    {
        char temp=curr[j];
        curr[j]=curr[i];
        curr[i]=temp;
        return curr;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        string target="123450";
        string initial="";
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                initial+=to_string(board[i][j]);
            }
        }
        int level=0;
        vector<vector<int>>vv{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        unordered_map<string,int>mp;
        queue<string>q;
        q.push(initial);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                string curr=q.front();
                q.pop();
                if(curr==target)
                {
                    return level;
                }
                int idx=-1;
                for(int j=0;j<curr.length();j++)
                {
                    if(curr[j]=='0')
                    {
                        idx=j;
                        break;
                    }
                }
                for(int j=0;j<vv[idx].size();j++)
                {
                    string add=swapping(curr,vv[idx][j],idx);
                    if(mp.find(add)!=mp.end())
                    {
                        continue;
                    }
                    q.push(add);
                    mp[add]++;
                }
            }
            level++;
        }
        return -1;
    }
};