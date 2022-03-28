class Solution {
public:
    int memo[50005][2];
    int helper(vector <int> &prices, int fee, int i, int flag)
    {
        if(i == prices.size())
            return 0;
        
        if(memo[i][flag] != -1)
            return memo[i][flag];
        
        if(flag)
        {
            // can only sell
            
            // decide to sell, 
            int ans1 = 0, ans2 = 0;
            
            ans1 = prices[i] - fee + helper(prices, fee, i+1, 0);
            
            // do not sell
            ans2 = helper(prices, fee ,i+1, 1);
            
            return memo[i][flag] = max(ans1, ans2);
            
        }
        else
        {
            // can only buy
            
            int ans1 = 0, ans2 = 0;
            
            // buy this one
            
            ans1 = -prices[i] + helper(prices, fee, i+1, 1);
            
            ans2 = helper(prices ,fee, i+1, 0);
            
            return memo[i][flag] = max(ans1, ans2);
        }
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        memset(memo, -1, sizeof memo);
        int ans = helper(prices, fee, 0, 0);
        return ans;
    }
};