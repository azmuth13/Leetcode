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
    
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m)
    {
        
        board[i][j] = 'D';
        
        if(good(board,i-1,j,n,m))
        {
            dfs(board,i-1,j,n,m);
        }
        if(good(board,i+1,j,n,m))
        {
            dfs(board,i+1,j,n,m);
        }
        if(good(board,i,j-1,n,m))
        {
            dfs(board,i,j-1,n,m);
        }
        if(good(board,i,j+1,n,m))
        {
            dfs(board,i,j+1,n,m);
        }
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
                    dfs(board, i, j, n, m);
                    
                    if(!check(board,n,m))
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