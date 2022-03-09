class Solution {
public:
    int tsum;
    
    int helper(vector <int> &nums, int sum, int &target, int i, int **dp)
    {
        
        if(i == nums.size() && sum == target)
        {
            //cout<<i<<endl;
            return 1;
        }
        
        if(i >= nums.size())
            return 0;
        
        if(dp[i][sum + tsum] != -1)
            return dp[i][sum + tsum];
        
        int ans = 0;
        
        // case 1 add this num
        ans += helper(nums, sum + nums[i], target, i+1,dp);
        
        // case 2 subtract this num
        ans += helper(nums, sum - nums[i], target, i+1,dp);
        
        dp[i][sum + tsum] = ans;
        return dp[i][sum + tsum];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
    
        tsum = accumulate(nums.begin(), nums.end(), 0);
        
        
        int ** dp = new int*[n+1];
        for(int i = 0; i <= n; i++)
        {
            dp[i] = new int[2*tsum+1];
            for(int j = 0; j <= 2*tsum; j++)
            {
                dp[i][j] = -1;
            }
        }
        
        //unordered_map <int, unordered_map <int, int> > dp;
        
        int ans = helper(nums, 0, target, 0, dp);
        return ans;
    }
};