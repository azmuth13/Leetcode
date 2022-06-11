class Solution {
public:
    
    vector<vector<char>> sol;
    
    bool okRow(int i, int j, vector<vector<char>>& board, int k)
    {
        for(int x = 0; x < 9; x++)
        {
            if(board[i][x] == (char)('0' + k))
                return false;
        }
        
        return true;
    }
    
    bool okCol(int i, int j, vector<vector<char>>& board, int k)
    {
        for(int y = 0; y < 9; y++)
        {
            if(board[y][j] == (char)('0' + k))
                return false;
        }
        
        return true;
    }
    
    bool okSub(int i, int j, vector<vector<char>>& board, int k)
    {
        int checki = i/3;
        
        int checkj = j/3;
        
        int startrow = 3*checki;
        
        int startcol = 3*checkj;
        
        for(int x = startrow; x < startrow + 3; x++)
        {
            for(int y = startcol; y < startcol + 3; y++)
            {
                if(board[x][y] == (char)('0' + k))
                    return false;
            }
        }
        
        return true;
        
    }
    
    bool helper(vector<vector<char>>& board, int i, int j)
    {
        if(i == 9)
        {    
            return true;
        }
        
        if(j == 9)
        {
            return helper(board, i+1, 0);
        }
        
        if(board[i][j] != '.')
            return helper(board, i, j+1);
        
        for(int c = 1; c <= 9; c++)
        {
            if(okRow(i, j, board, c) &&
                okCol(i, j, board, c) &&
                    okSub(i, j, board, c))
                    {
                        board[i][j] = (char)('0' + c);
                        if(helper(board, i, j+1))
                            return true;

                        board[i][j] = '.';
                    }
        }
            
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
            
        helper(board, 0, 0);
        
    }
};