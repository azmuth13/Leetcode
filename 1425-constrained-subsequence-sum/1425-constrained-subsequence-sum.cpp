class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector <int> dp(n+1,0);
        priority_queue <pair <int, int> , vector <pair <int, int> >> pq;
        dp[0] = nums[0];
        pq.push({dp[0],0});
        for(int j = 1; j < n; j++)
        {
            
            while(pq.size() > 0 && pq.top().second < j-k)
                pq.pop();
            
            dp[j] = nums[j];
            
            dp[j] = max(dp[j], nums[j] + pq.top().first);
            
            pq.push({dp[j], j});
            // dp[j] = nums[j];
            // for(int i = j-1; i >= 0; i--)
            // {
            //     if(j-i > k)
            //         break;
            //     dp[j] = max(dp[j], dp[i] + nums[j]);
            // }
        }

        int ans = -1e9;
        for(int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};