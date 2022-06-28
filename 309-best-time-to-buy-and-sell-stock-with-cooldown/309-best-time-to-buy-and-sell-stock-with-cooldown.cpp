class Solution {
public:
    int memo[5001][2];
    int helper(int i, int bought, vector <int> &prices)
    {
        if(i >= prices.size())
            return 0;
        if(memo[i][bought] != -1) return memo[i][bought];
        if(!bought)
        {
            // buy
            int ans1 = -prices[i] + helper(i+1,1,prices);
            
            // not buy
            int ans2 = helper(i+1,0,prices);
            return memo[i][bought] = max(ans1, ans2);
        }
        else
        {
            // sell
            int ans1 = prices[i] + helper(i+2,0,prices);
            
            // not sell
            int ans2 = helper(i+1,1,prices);
            return memo[i][bought] = max(ans1, ans2);
        }
        
        return -1e9;
    }
    
    int maxProfit(vector<int>& prices) {
        memset(memo,-1,sizeof memo);
        int bought = 0;
        int ans = helper(0,bought,prices);
        return ans;
    }
};