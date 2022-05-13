class Solution {
public:
    int jump(vector<int>& nums) {
    

        int n = nums.size();
        
        int i = 0, ans = 0;
        int end = 0, farthest = 0;
        
        while(i < n && end < n-1)
        {
            ans++;
            
            while(i < n && i <= end)
            {
                farthest = max(farthest, i + nums[i]);
                i++;
            }
            
            end = farthest;

        }
        return ans;
    }
};