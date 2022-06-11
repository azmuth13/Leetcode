class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        
        // max length subarray with sum = target
        // target = totalSum - x; 
        
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        
        int target = sum - x;
        
        if(target < 0)
            return -1;
        
        if(target == 0)
            return n;
        
        unordered_map <int, int> mp;
        mp[0] = -1;
        int pre = 0;
        int len = 0;
        
        for(int i = 0; i < n; i++)
        {
            pre += nums[i];
           
            
            if(mp.find(pre-target) != mp.end())
            {
                //cout << pre << endl;
                len = max(len, i - mp[pre-target]);
            }
            mp[pre] = i;
        }
        
        //cout << len << endl;
        int res = n-len;
        if(res < 0 || len == 0)
            res = -1;
        
        return res;
    }
};