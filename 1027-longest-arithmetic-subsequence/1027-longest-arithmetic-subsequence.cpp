class Solution {
public:
    
    int helper(vector <int> &nums, int d)
    {
        map <int, int> mp;
        
        int n = nums.size();
        int res = 1;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(nums[i] - d) != mp.end())
            {
                mp[nums[i]] = max(mp[nums[i]], 1 + mp[nums[i] - d]);
                res = max(res, mp[nums[i]]);
            }
            mp[nums[i]] = max(1, mp[nums[i]]);
        }
        return res;
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        
        // set <int> st;
        int n = nums.size();
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = i+1; j < n; j++)
//             {
//                 st.insert(nums[j] - nums[i]);
//             }
//         }
        
         int ans = 1;
        
//         for(auto &x : st)
//         {
//             ans = max(ans, helper(nums, x));    
//         }
        //unordered_map <int, unordered_map <int, int> > dp;
        
         vector < vector <int> > dp(2001, vector <int> (2001, 1));
        
//         for(int i = 0; i < n; i++)
//         {
//             for(int d = -500; d <= 500; d++)
//             {
//                 dp[nums[i] + 500][d + 500] = max(1 + dp[nums[i] + d + 500][d + 500], dp[nums[i] + 500][d + 500]);
//                 ans = max(ans, dp[nums[i] + 500][d + 500]);
//             }
//         }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                dp[i][nums[i]-nums[j]+500] = max(dp[i][nums[i]-nums[j]+500], 1 + dp[j][nums[i]-nums[j]+500]);
                ans = max(ans, dp[i][nums[i]-nums[j]+500]);
            }
        }
        return ans;
    }
};