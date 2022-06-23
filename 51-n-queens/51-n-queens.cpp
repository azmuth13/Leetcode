class Solution {
public:
    
//     bool hGood(vector <string> &board, int i, int j)
//     {
//         int n = board.size();
//         for(int k = 0; k < n; k++)
//         {
//             if(board[i][k] == 'Q')
//                 return false;
//         }
//         return true;
//     }
    
    
    bool vGood(vector <string> &board, int i, int j)
    {
        int n = board.size();
        for(int k = 0; k < n; k++)
        {
            if(board[k][j] == 'Q')
                return false;
        }
        return true;
    }
    
    bool dsGood(vector <string> &board, int i, int j)
    {
        int n = board.size();
        
        int a = i-1, b = j-1;
        while(a >= 0 && b >= 0)
        {
            if(board[a][b] == 'Q') return false;
            a--,b--;
        }
        
        a = i+1,b = j+1;
        while(a < n && b < n)
        {
            if(board[a][b] == 'Q') return false;
            a++,b++;
        }
        
        
        a = i-1,b= j+1;
        while(a >= 0 && b < n)
        {
            if(board[a][b] == 'Q') return false;
            a--,b++;
        }
        
        a = i+1,b = j-1;
        while(a < n && b >= 0)
        {
            if(board[a][b] == 'Q') return false;
            a++,b--;
        }
        return true;
    }
    
    
    vector<vector<string>> result;
    
    void helper(int n, vector <string> &board, int i)
    {
        if(i == n)
        {
            result.push_back(board);
            return;
        }
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == '.')
            {
                if(vGood(board,i,j) && dsGood(board,i,j))
                {
                    board[i][j] = 'Q';
                    helper(n,board,i+1);
                    board[i][j] = '.';
                }
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector <string> board(n, string(n,'.'));
        helper(n,board,0);
        
        return result;
    }
};