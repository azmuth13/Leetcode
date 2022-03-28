class Solution {
public:
    int memo[40][1005];
    int mod = 1e9 + 7;
    int helper(int i, int n, int k, int target)
    {
        if(target == 0 && i == n+1)
            return 1;
        
        if(i >= n+1 || target < 0)
            return 0;
        
        if(memo[i][target] != -1)
            return memo[i][target];
        
        int ans = 0;
        
        for(int f = 1; f <= k; f++)
        {
            ans += helper(i+1, n, k, target - f);
            ans %= mod;
        }
        
        return memo[i][target] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(memo, -1, sizeof memo);
        int ans = helper(1, n, k, target);
        
        return ans;
    }
};