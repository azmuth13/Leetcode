class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;
        
            
        for(int i = 2; i < n; i++)
        {
            int diff = nums[i] - nums[i-1];
            
            int j = i-2;
            
            while((j >= 0) && ((nums[j+1] - nums[j]) == diff))
            {
                ans++;
                j--;
            }
            
        }
        
        return ans;
    }
};