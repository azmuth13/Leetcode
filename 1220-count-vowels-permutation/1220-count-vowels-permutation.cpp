class Solution {
public:
    int mod = 1e9 + 7;
    int memo[20005][30];
    int helper(int n, char ch)
    {
        if(n == 0)
        {
            return 1;
        }
        
        if(memo[n][ch-'a'] != -1)
            return memo[n][ch-'a'];
        
        int ans = 0;
        
        if(ch-'a' == 0)
        {
            // a
            
            ans += helper(n-1, 'e');
            ans %= mod;
        }
        
        if(ch == 'e')
        {
            ans += helper(n-1, 'a');
            ans %= mod;
            ans += helper(n-1, 'i');
            ans %= mod;
        }
        
        if(ch == 'i')
        {
            ans += helper(n-1, 'a');
            ans %= mod;
            ans += helper(n-1, 'e');
            ans %= mod;
            ans += helper(n-1, 'o');
            ans %= mod;
            ans += helper(n-1, 'u');
            ans %= mod;
        }
        
        if(ch == 'o')
        {
            ans += helper(n-1, 'i');
            ans %= mod;
            ans += helper(n-1, 'u');
            ans %= mod;
        }
        
        if(ch == 'u')
        {
            ans += helper(n-1, 'a');
            ans %= mod;
        }
        
        return memo[n][ch-'a'] = ans;
    }
    
    int countVowelPermutation(int n) {
        
        n--;
        memset(memo, -1, sizeof memo);
        int ans = helper(n, 'a');
        ans %= mod;
        ans += helper(n, 'e');
        ans %= mod;
        ans += helper(n, 'i');
        ans %= mod;
        ans += helper(n, 'o');
        ans %= mod;
        ans += helper(n, 'u');
        ans %= mod;
        
        return ans;
        
    }
};