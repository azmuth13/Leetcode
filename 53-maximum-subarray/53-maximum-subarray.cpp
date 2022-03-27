class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;
        int ans = -1*1e6;
        
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            
            if(sum > ans)
                ans = sum;
            
            if(sum < 0)
                sum = 0;
        }
        
        return ans;
        
    }
};