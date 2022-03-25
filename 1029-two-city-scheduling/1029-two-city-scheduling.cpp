class Solution {
public:
    
    int memo[201][201][201];
    
    int helper(vector<vector<int>>& costs, int i, int c1, int c2)
    {
        int n = costs.size()/2;
        
        if(c1 == n && c2 == n)
        {
            return 0;
        }
        
        if(c1 > n || c2 > n)
        {
            return 1e9;
        }
        
        if(i >= costs.size())
        {
            return 1e9;
        }
        
        if(memo[i][c1][c2] != -1)
            return memo[i][c1][c2];
        
        int ans1 = costs[i][0] + helper(costs, i+1, c1+1, c2);
        
        int ans2 = costs[i][1] + helper(costs, i+1, c1, c2+1);
        
        return memo[i][c1][c2] = min(ans1, ans2);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        memset(memo, -1, sizeof(memo));
        
        int ans = helper(costs, 0, 0, 0);
        return ans;
        
    }
};