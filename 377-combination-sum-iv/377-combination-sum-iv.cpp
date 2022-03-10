class Solution {
public:
    
//     int helper(vector <int> &coins, int n, int x, int i)
//     {
//         if(x == 0) return 1;

//         if(i >= n || x < 0) return 0;
//         int ans1 = 0, ans2 = 0;
//         ans1 = helper(coins, n, x - coins[i], i);
//         ans2 = helper(coins, n, x, i+1);
//         return (ans1 + ans2);
//     }
    
int dp[1000001];
 
int helper(vector <int> &coins, int n, int x)
{
 
    if(x==0)
        return 1;
 
    if(dp[x] != -1)
        return dp[x];
 
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(coins[i] > x)
            break;
 
        ans += helper(coins, n, x - coins[i]);
    }
 
    return dp[x] = ans;
}
 
    
    int combinationSum4(vector<int>& nums, int target) {
        
        int n = nums.size();
        for(int i = 0; i <= target; i++)
        {
            dp[i] = -1;
        }
        sort(nums.begin(), nums.end());
        int ans = helper(nums, n, target);
        return ans;
    }
};