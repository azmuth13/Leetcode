class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        int sum1 = 0, sum2 = 0;
        int maxi = nums[0], mini = nums[0];
        int tot = 0;
        for(int i = 0; i < n; i++)
        {
            tot += nums[i];
            sum1 += nums[i];
            maxi = max(maxi, sum1);
            if(sum1 < 0)
            {
                sum1 = 0;
            }
            
            sum2 += nums[i];
            mini = min(mini, sum2);
            if(sum2 > 0)
            {
                sum2 = 0;
            }
        }
        //cout << mini << ' ' << maxi << endl;
        if(maxi < 0)
            return maxi;
        
        return max(maxi, tot-mini);
        
        
        return 0;
        
    }
};