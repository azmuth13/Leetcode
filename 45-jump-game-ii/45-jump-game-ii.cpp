class Solution {
public:
    int jump(vector<int>& nums) {
    

        
        
        int n = nums.size();
        
        vector <int> dp(n+1, 1e9);
        dp[n-1] = 0;
        dp[n] = 0;
        int maxi = nums[n-1];
        
        for(int i = n-2; i >= 0; i--)
        {
            int mini = 1e9;
            int k = 0;
            int j;
     
            for(j = i+1; j < n; j++)
            {
                if(k >= nums[i])
                    break;

                if(mini > dp[j])
                {
                    mini = dp[j];
                }
                
                k++;
            }
            
            dp[i] = min(dp[i],mini + 1);
        }
        
        return dp[0];
    }
};