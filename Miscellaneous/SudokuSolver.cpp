class Solution {
public:
    vector<vector<char>> ans;
    bool safe(vector<vector<char>>& board,int row,int col,char ch)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==ch)
            {
                return false;
            }
        }
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==ch)
            {
                return false;
            }
        }
        int x = (row/3)*3;
        int y = (col/3)*3;
        
        for(int i = x; i<(x+3); i++)
        {
            for(int j = y; j<(y+3); j++)
            {
                if(board[i][j] == ch)
                    return false;
            }
        }
        return true;
    }
    void sudoku(vector<vector<char>>& board,int row,int col)
    {
        if(row==9)
        {
            ans=board;
            return;
        }
        if(col==9)
        {
            sudoku(board,row+1,0);
            return;
        }
        if(board[row][col]!='.')
        {
           sudoku(board,row,col+1);
            return;
        }
        for(char i='1';i<='9';i++)
        {
            if(safe(board,row,col,i))
            {
                board[row][col]=i;
                sudoku(board,row,col+1);
                board[row][col]='.';
            }
        }
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board,0,0); 
        board=ans;
    }
};