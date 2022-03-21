class Solution {
public:

    int helper(vector <int>& piles, int i, int m, vector <vector <int> > &dp )
    {
        if(i >= piles.size())
        {
            return 0; 
        }
        
        if(dp[i][m] != -1)
            return dp[i][m];
        
        int n = piles.size();
        
        int ans = -1e9;
        int s = 0;
        
        for(int x = i; x < (i + 2*m) && x < n; x++)
        {
            s += piles[x];
            ans = max(ans, s - helper(piles, x+1, max(x-i+1,m), dp));
        }
        
        return dp[i][m] = ans;
    }
    
    int stoneGameII(vector<int>& piles) {
        
        
        
        int n = piles.size();
        int m = 1;
        vector < vector <int> > dp(n+1, vector <int>(n+1, -1));
        int ans = helper(piles, 0, m, dp);
        int sum = accumulate(piles.begin(), piles.end(), 0);
        return (ans + sum)/2;
        
    }
};