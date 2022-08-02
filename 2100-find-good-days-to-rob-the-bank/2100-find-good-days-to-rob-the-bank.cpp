class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        vector <int> ans;
        int n = nums.size();
        
        vector <int> left(n,0), right(n,0);
        
        int streak = 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] <= nums[i-1])
                streak++;
            else
                streak = 0;
            left[i] = streak;
        }
        streak = 0;
        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] <= nums[i+1])
                streak++;
            else
                streak = 0;
            right[i] = streak;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(i-time < 0 || i+time >= n) continue;

            if(left[i] < time || right[i] < time) continue;
            
            ans.push_back(i);
        }
        return ans;
    } 
};