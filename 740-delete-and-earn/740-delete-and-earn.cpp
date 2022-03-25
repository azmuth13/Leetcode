class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector <int> cnt(20001, 0), dp(20001, 0);
        for(auto x : nums)
        {
            cnt[x]++;
        }
        dp[0] = 0;
        dp[1] = cnt[1];
            
        for(int i = 2; i <= 20000; i++)
        {
            dp[i] = max(dp[i-1], cnt[i]*i + dp[i-2]);
        }
        return dp[20000];
    }
};