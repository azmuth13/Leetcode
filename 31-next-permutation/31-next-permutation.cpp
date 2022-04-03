class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // find first violated num
        
        int i;
        int n = nums.size();
        
        for( i = n-2; i>= 0 ; i--)
        {
            if(nums[i] < nums[i+1])
                break;
        }
        
        reverse(nums.begin() + i + 1, nums.end());
        
        if(i == -1)
            return;
        
        for(int j = i+1; j < n; j++)
        {
            if(nums[j] > nums[i])
            {
                swap(nums[i], nums[j]);
                break;
            }
                
        }
        
        
        
    }
};