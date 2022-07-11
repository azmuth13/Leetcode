class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        
        vector <int> dp(n,0);
        dp[0] = 0;
        int cntOne = (s[0] == '1');
        for(int i = 1; i < n; i++)
        {
            if(s[i] == '0')
            {
                dp[i] = min(dp[i-1]+1,cntOne);
            }
            else
            {
                cntOne++;
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};