class Solution {
public:
    int mod = 1e9 + 7;
    int N;
    int memo[1001][2];
    int helper(int i, int flag)
    {   
        if(i >= N-1)
        {
            if(flag == 0)
            return 1;

            return 0;
        }

        if(memo[i][flag] != -1)
            return memo[i][flag];

        int ans = 0;
        if(flag == 0)
        {
            ans += helper(i+1,0);
            ans %= mod;
            ans += helper(i+2,0);
            ans %= mod;

            ans += 2*helper(i+1, 1)%mod;
            ans %= mod;
        }
        else
        {
            ans += helper(i+2,0);
            ans %= mod;
            ans += helper(i+1,1);
            ans %= mod;
        }
        return memo[i][flag] = ans;
    }

    int numTilings(int n) {

        N = n;
        for(int i = 0; i <= n; i++)
        {
            memo[i][0] = memo[i][1] = -1;
        }
        int ans = helper(0, 0);
        return ans;
    }

};