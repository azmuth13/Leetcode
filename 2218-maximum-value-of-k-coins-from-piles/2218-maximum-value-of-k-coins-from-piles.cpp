class Solution {
public:
    int memo[1001][2002];
    int helper(vector<vector<int>>& piles, int k, int i)
    {
        if(i == piles.size())
        {
            if(k == 0)
                return 0;
            
            return -2e9;
        }
        
        if(memo[i][k] != -1)
            return memo[i][k];
        
        int ans = 0;
        int s = 0;
        
        int take = k;
        
        // take it
        for(int j = 0; j < piles[i].size(); j++)
        {
            if(take == 0)
                break;
            
            s += piles[i][j];
            ans = max(ans, s + helper(piles, take - 1, i+1));
            take--;
        }
        // leave
        ans = max(ans, helper(piles, k, i+1));
        
        return memo[i][k] = ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int ans = 0;
        
        int n = piles.size();
        
        memset(memo, -1, sizeof(memo));
        
        ans = helper(piles, k, 0);
        
        return ans;
        
        /*
        [[37,88],[51,64,65,20,95,30,26],[9,62,20],[44]]
        9
        
        https://www.careercup.com/question?id=5711620404674560
        */
    }
};