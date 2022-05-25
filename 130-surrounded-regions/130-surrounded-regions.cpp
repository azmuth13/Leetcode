class Solution {
public:
    bool good(vector<vector<char>>& board, int i, int j, int n, int m)
    {
        return (i >=0 && j >=0 && i < n & j < m && board[i][j] == 'O');
    }
    
    void fillX(vector<vector<char>>& board, int n, int m)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'D')
                    board[i][j] = 'X';
            }
        }
    }
    
    void fillO(vector<vector<char>>& board, int n, int m)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'D')
                    board[i][j] = 'O';
            }
        }
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j, int n, int m)
    {
        
        board[i][j] = 'D';
        if(i == 0 || i == n-1 || j == 0 || j == m-1)
            return false;
        
        bool res = true;
        if(good(board,i-1,j,n,m))
        {
            res &= dfs(board,i-1,j,n,m);
            if(!res)
                return false;
        }
        if(good(board,i+1,j,n,m))
        {
            res &= dfs(board,i+1,j,n,m);
            if(!res)
                return false;
        }
        if(good(board,i,j-1,n,m))
        {
            res &=dfs(board,i,j-1,n,m);
            if(!res)
                return false;
        }
        if(good(board,i,j+1,n,m))
        {
            res &=dfs(board,i,j+1,n,m);
            if(!res)
                return false;
        }
        return res;
    }
    
    bool check(vector<vector<char>>& board, int n, int m)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'D' && (i == 0 || j == 0 || i == n-1 || j == m-1))
                    return true;
            }
        }
        return false;
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0;  j<m; j++)
            {
                if(board[i][j] == 'O')
                {
                    bool res = dfs(board, i, j, n, m); // n*m
                    if(res)
                    {
                        fillX(board,n,m);
                    }
                    else
                    {
                        fillO(board,n,m);
                    }
                }
            }
        }
    }
};