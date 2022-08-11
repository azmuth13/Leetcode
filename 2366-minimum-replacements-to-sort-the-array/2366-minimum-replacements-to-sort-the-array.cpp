class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        int ahead = nums[n-1];
        long long int cnt = 0;
        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] <= ahead)
            {
                ahead = nums[i];
            }
            else
            {
                int times = 0;
                if(nums[i]%ahead == 0)
                    times = nums[i]/ahead;
                else
                    times = nums[i]/ahead + 1;
                // cout << times << ' ' << times * ahead << ' ' << nums[i] << endl;
                ahead = nums[i]/times;
                cnt += times-1;
            }
            
        }
        return cnt;
    }
};