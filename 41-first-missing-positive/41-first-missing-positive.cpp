class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= 1 && nums[i] <= n)
            {
                int pos = nums[i]-1;
                if(nums[pos] != nums[i])
                {
                    swap(nums[pos], nums[i]);
                    i--;
                }
            }
        }
        for(int i = 0; i < n; i++)
            if(nums[i] != i+1)
                return i+1;
        return n+1;
    }
};