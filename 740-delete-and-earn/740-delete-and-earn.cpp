class Solution {
public:
    using ll = long long;
    
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        
        vector <ll> dp(20001, 0), cnt(20001, 0);
        
        for(int i = 0; i < n; i++)
        {
            cnt[nums[i]]++;
        }
        
        if(n==1)
            return nums[0];
        
        dp[0] = 0;
        dp[1] = 1*cnt[1];// cnt[nums[1]];
        
        for(int i = 2; i <= 20000; i++)
        {
            dp[i] = max(dp[i-1], i*cnt[i] + dp[i-2]);
        }
        
        return dp[20000];
    }
};