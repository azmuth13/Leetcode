class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int first = 0;
        
        int ans = 0;
            
        int zeroes = 0;
        int second = 0;
        while(second < n)
        {
            if(nums[second] == 0)
                zeroes++;
            
            
            while(zeroes > k)
            {
                if(nums[first] == 0)
                    zeroes--;
                
                first++;
            }
            
            ans = max(ans, second - first + 1);
            second++;
        }
        
        return ans;
    }
};