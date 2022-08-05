class Solution {
public:
    int memo[200005];
    int helper(vector<int>& nums, int target)
    {
        if(target==0)
            return 1;
        
        if(target < 0) return 0;
        
        if(memo[target] != -1) return memo[target];
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            ans += helper(nums, target-nums[i]);
        }
        return memo[target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        
        memset(memo,-1,sizeof memo);
        int ans = helper(nums, target);
        return ans;
    }
};