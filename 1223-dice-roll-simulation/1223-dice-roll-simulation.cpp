class Solution {
public:
    int mod = 1e9 + 7;
    int memo[5001][7][16];
    int helper(int n, int last, int lastFreq, vector<int>& rollMax)
    {
        if(n == 0)
            return 1;
        if(memo[n][last][lastFreq] != -1) return memo[n][last][lastFreq];
        int ans = 0;
        for(int i = 1; i <= 6; i++)
        {
            if(i == last)
            {
                if(lastFreq < rollMax[i-1])
                {
                    ans += helper(n-1,i,lastFreq+1,rollMax);
                    ans %= mod;
                }
            }
            else
            {
                ans += helper(n-1,i,1,rollMax);
                ans %= mod;
            }
        }
        return memo[n][last][lastFreq] = ans;
    }
    
    int dieSimulator(int n, vector<int>& rollMax) {
        int ans = 0;
        memset(memo,-1,sizeof memo);
        for(int i = 1; i <= 6; i++)
        {
            ans += helper(n-1,i,1,rollMax);
            ans %= mod;
        }
        return ans;
    }
};