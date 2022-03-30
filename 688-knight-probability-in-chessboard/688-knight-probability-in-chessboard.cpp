class Solution {
public:
    
    double memo[30][30][130];
    
    double helper(int r, int c, int n, int k)
    {
        if(r >= n || c >= n || r < 0 || c < 0)
        {
            return 0;
        }
        
        if(k == 0)
        {
            return 1;
        }
        
        if(memo[r][c][k] != -1)
            return memo[r][c][k];
        
        double ans = 0;
        
        
        ans += helper(r+2, c+1, n, k-1);
        ans += helper(r+2, c-1, n, k-1);
        ans += helper(r-2, c+1, n, k-1);
        ans += helper(r-2, c-1, n, k-1);
        ans += helper(r+1, c+2, n, k-1);
        ans += helper(r-1, c+2, n, k-1);
        ans += helper(r+1, c-2, n, k-1);
        ans += helper(r-1, c-2, n, k-1);
        
        return memo[r][c][k] = ans/(8.0);
        
    }
    
    double knightProbability(int n, int k, int r, int c) {
        
        
        for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < 30; j++)
            {
                for(int k = 0; k < 130; k++)
                    memo[i][j][k] = -1*1.00;
            }
        }
        return helper(r, c, n, k);
        
        //return (good)/(total);
    }
};