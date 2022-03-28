class Solution {
public:
    
    int memo[400][400];
    int helper(vector<int>& days, vector<int>& costs, int i, int currDay)
    {
        if(i == days.size())
            return 0;
        
        if(currDay >= days.back())
            return 0;
        
        if(memo[i][currDay] != -1)
            return memo[i][currDay];
        
        if(currDay < days[i])
        {
            // buy pass
            int ans1 = 1e9, ans2 = 1e9, ans3 = 1e9;
            
            ans1 = costs[0] + helper(days, costs, i, days[i] + 1-1);
            ans2 = costs[1] + helper(days, costs, i, days[i] + 7-1);
            ans3 = costs[2] + helper(days, costs, i, days[i] + 30-1);
            
            return memo[i][currDay] = min(ans1, min(ans2, ans3));
        }
        else
        {
            // currday >= days[i]
            return memo[i][currDay] = helper(days, costs, i+1, currDay);
        }
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(memo, -1, sizeof memo);
        int ans = helper(days, costs, 0, 0);
        return ans;
    }
};