class Solution {
public:
    int memo[160001][17];
    bool helper(vector <int> &nums, int mask, int &each, int currSum, int i, int k)
    {
        
        if(k == 1)
            return true;
        
        if(currSum == 0)
        {
            return memo[mask][k] = helper(nums, mask, each, each, 0, k-1);
        }
        
        if(memo[mask][k] != -1)
            return memo[mask][k];
        
        for(int j = i; j<nums.size(); j++)
        {
            if((mask & (1<<j)) || currSum - nums[j] < 0)
                continue;

            if(helper(nums, mask|(1<<j), each, currSum - nums[j], j+1, k))
                return memo[mask][k] = true;
        }
        
        return memo[mask][k] = false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int sum = 0;
        
        for(int i = 0; i<n; i++)
        {
            sum += nums[i];
        }
        
        if(sum % k || n < k)
        {
            return false;
        }
        
        int each = sum/k;
        
        // visited + if not possible then backtrack and explore other 
        // options
        
        // vector <int> vis(n+1, 0);
        int mask = 0;
        int currSum = each;
        memset(memo,-1,sizeof memo);
        bool ans = helper(nums, mask, each, currSum, 0, k);
        
        return ans;
    }
};