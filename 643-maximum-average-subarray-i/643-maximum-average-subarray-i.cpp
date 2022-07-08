class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -1e9;
        int n = nums.size();
        
        for(int i = 1; i < n; i++)
        {
            nums[i] += nums[i-1];
        }
        
        for(int i = k-1; i < n; i++)
        {
            double avg = nums[i]-(((i-(k-1)-1)>=0)?nums[i-(k-1)-1]:0);
            avg/=(double)k;
            ans = max(ans,avg);
        }
        return ans;
    }
};