class Solution {
public:
    
    int dp[105][105][205];
    
    int helper(vector<vector<char>>& grid, int cnt, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        if(i == n-1 && j == m-1)
        {
            if(grid[i][j] == '(') return 0;
            cnt--;
            return (cnt == 0);
        }
        
        if(i >= n || j >= m || cnt < 0) return 0;
        
        if(dp[i][j][cnt] != -1) return dp[i][j][cnt];

        int a = 0, b = 0;
        
        if(grid[i][j] == '(')
            return dp[i][j][cnt] = (helper(grid, cnt + 1, i+1, j) || helper(grid, cnt+1, i, j+1));
        else
             return dp[i][j][cnt] = (helper(grid, cnt - 1, i+1, j) || helper(grid, cnt - 1, i, j+1));
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {

        memset(dp, -1, sizeof dp);
        int ans = helper(grid, 0, 0,0);
        if(ans > 0) return true;
        
        return false;
    }
};