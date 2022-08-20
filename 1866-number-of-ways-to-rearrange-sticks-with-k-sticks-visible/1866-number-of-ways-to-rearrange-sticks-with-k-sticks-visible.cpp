

class Solution {
public:
    int mod = 1e9 + 7;
    long long dp[1001][1001] = {};
    int helper(int n, int k)
    {
        if(n==k)
            return 1;
        if(k==0)
            return 0;
        if(dp[n][k] != 0)
            return dp[n][k];
        
        dp[n][k] += helper(n-1,k-1);
        dp[n][k]%=mod;
        
        dp[n][k] += (1ll*(n-1)*helper(n-1,k)%mod)%mod;
        dp[n][k]%=mod;
        return dp[n][k];
        
    }
    int rearrangeSticks(int n, int k) {
        int ans = helper(n,k);
        return ans;
    }
};