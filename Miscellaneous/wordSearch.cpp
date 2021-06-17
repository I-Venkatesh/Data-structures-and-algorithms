class Solution {
public:

    int X[4]={1,-1,0,0};
    int Y[4]={0,0,1,-1};
    bool dfs(vector<vector<char>>& board, string word,int m,int n,int i,int j,int w)
    {
        if(w==word.length())
        {
            return true;
        }
        if(i>=m||i<0||j>=n||j<0)
        {
            return false;
        }
        if(word[w]!=board[i][j])
        {
            return false;
        }
        board[i][j]='*';
        bool curr=false;
        for(int s=0;s<4;s++)
        {
            curr|=dfs(board, word, m, n, i+X[s], j+Y[s],w+1);
        }
        board[i][j]=word[w];
        return curr;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        bool answer=false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                 if(dfs(board,word,m,n,i,j,0))
                {
                     return true;
                }
            }
        }
        return false;
    }
};