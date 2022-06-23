class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if(nums.size() < 2)
            return false;
        
        if(k == 1)
            return true;
        
        for(int i = 1; i < nums.size(); i++)
        {
            if((nums[i] == 0 && nums[i-1] == 0) || (nums[i] == k && nums[i-1] == 0) ||  (nums[i] == 0 && nums[i-1] == k))
                return true;
        }
        
        map <int, int> mp;
    
        int sum = nums[0];
        mp[sum] = 0;
        
        for(int i = 1; i < nums.size(); i++)
        {
            sum += nums[i];
            if(sum%k == 0)
                return true;
            
            int val = 0;
            while(val <= sum)
            {
                if(mp.find(sum-val) != mp.end())
                {
                    if(i - mp[sum-val] >= 2)
                        return true;
                }
                val+=k;
            }
            mp[sum] = i;
        }
        
        return false;
    }
};