int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();

class Solution {
public:
    
//     int helper(vector <int> &nums, int d)
//     {
//         map <int, int> mp;
        
//         int n = nums.size();
//         int res = 1;
//         for(int i = 0; i < n; i++)
//         {
//             if(mp.find(nums[i] - d) != mp.end())
//             {
//                 mp[nums[i]] = max(mp[nums[i]], 1 + mp[nums[i] - d]);
//                 res = max(res, mp[nums[i]]);
//             }
//             mp[nums[i]] = max(1, mp[nums[i]]);
//         }
//         return res;
//     }
    
    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();

        int ans = 1;
        
        vector < vector <int> > dp(2001, vector <int> (2001, 0));
        
        for(int d = -500; d <= 500; d++)
        {
            for(int i = 0; i < n; i++)
            {
                dp[nums[i] + 500][d+500] = max(dp[nums[i] + d + 500][d+500] + 1, 
                                              dp[nums[i] + 500][d+500]);
                 ans = max(ans, dp[nums[i] + 500][d + 500]);
            }
        }
        
        return ans;
    }
};