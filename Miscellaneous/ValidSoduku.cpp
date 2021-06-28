class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            int freq[11];
            memset(freq,0,sizeof(freq));
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    freq[board[i][j]-'0']++;
                }
            }
            for(int m=0;m<10;m++)
            {
                if(freq[m]>1)
                {
                    return false;
                }
            }
        }
        for(int i=0;i<9;i++)
        {
            int freq[11];
            memset(freq,0,sizeof(freq));
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.')
                {
                    freq[board[j][i]-'0']++;
                }
            }
            for(int m=0;m<10;m++)
            {
                if(freq[m]>1)
                {
                    return false;
                }
            }
        }
        for(int i=0;i<=6;i+=3)
        {
            for(int j=0;j<=6;j+=3)
            {
                int freq[11];
                memset(freq,0,sizeof(freq));
                for(int k=i;k<i+3;k++)
                {
                    for(int l=j;l<j+3;l++)
                    {
                        if(board[k][l]!='.')
                        {
                            freq[board[k][l]-'0']++;
                        }
                    }
                }
                for(int m=0;m<10;m++)
                {
                    if(freq[m]>1)
                    {
                        return false;
                    }
                }       
            }
        }
        return true;
    }
};