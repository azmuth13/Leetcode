class Solution {
public:
    int ans;
    int memo[21][5001];
    int helper(vector<int>& rods, int i, int sum)
    {
        if(i == rods.size())
        {
            if(sum == 0)
            {
                return 0;
            }
            return -1e9;
        }
        
        if(memo[i][abs(sum)] != -1)
            return memo[i][abs(sum)];
        
        int ans1 = rods[i] + helper(rods, i+1, sum + rods[i]);
        int ans2 = rods[i] + helper(rods, i+1, sum - rods[i]);
        int ans3 = helper(rods, i+1, sum);
        
        return memo[i][abs(sum)] = max(ans1, max(ans2, ans3));
    }
    
    
    int tallestBillboard(vector<int>& rods) {
        ans = 0;
        memset(memo, -1, sizeof memo);
        ans = helper(rods, 0, 0);
        return ans/2;
    }
};