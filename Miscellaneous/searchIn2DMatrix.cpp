class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,j=matrix[0].size()-1;
        int row=matrix.size(),col=matrix[0].size();
        while(i>=0&&i<row&&j>=0&&j<col)
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
            else if(matrix[i][j]>target)
            {
                j--;
            }
            else{
                i++;
            }

        }
        return false;
    }
};