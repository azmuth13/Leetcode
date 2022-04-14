class Solution {
public:
    int memo[10001];
    int helper(int n)
    {
        if(n < 0) return 1e9;
        if(n == 0) return 0;
        if(memo[n] != -1) return memo[n];
        int ans = 1e9;
        for(int i = 1; i*i <= n; i++)
            ans = min(ans, 1 + helper(n - i*i));
        return memo[n] = ans;
    }
    int numSquares(int n) {
        memset(memo, -1, sizeof memo);
        return helper(n);
    }
};