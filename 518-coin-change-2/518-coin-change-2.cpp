class Solution {
public:
    int memo[301][5001];
    int helper(vector <int> &coins, int n, int x, int i)
    {
        if(x == 0) return 1;

        if(i >= n || x < 0) return 0;
        
        if(memo[i][x] != -1)
            return memo[i][x];
        
        int ans1 = 0, ans2 = 0;
        ans1 = helper(coins, n, x - coins[i], i);
        ans2 = helper(coins, n, x, i+1);
        return memo[i][x] = (ans1 + ans2);
    }

    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        // for(int i = 0; i <= n; i++)
        // {
        //     for(int j = 0; j <= amount; j++)
        //         memo[i][j] = -1;
        // }
        // int res = helper(coins, n, amount, 0);
        // return res;
        
        
        int dp[5001] = {};
        
        
        dp[0] = 1;
        
//         for(int i = 0; i <= n; i++)
//         {
//             for(int j = 0; j <= amount; j++)
//                 memo[i][j] = 0;
            
//             memo[i][amount] = 1;
//         }
        
        
        
//         for(int currSum = 0; currSum <= amount; currSum++)
//         {
//             for(int j = 1; j <= n; j++)
//             {
//                 int ans = 0;
                
//                 if(coins[j-1] <= currSum)
//                 {
//                     memo[j][currSum] = memo[j][currSum - coins[j-1]] + memo[j][currSum];
//                 }
//                 else
//                 memo[j][currSum] = memo[j-1][currSum];

//             }
//         }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= amount; j++)
            {
                if(j >= coins[i])
                    dp[j] += dp[j - coins[i]];
                    
            }
        }
        
        // for(int i = 0; i <= amount; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         if(i - coins[j] >= 0)
        //         {
        //             dp[i] += dp[i - coins[j]];
        //         }
        //     }
        // }
        
        return dp[amount];
        
        //return memo[n][amount];
    }
};