class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
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
        
        int len = 0;
        
        int l = 0, r = 0;
        int p = 0;
        while(r < n)
        {
            if(p + nums[r] < target)
            {
                p += nums[r];
                r++;
            }
            else if(p + nums[r] > target)
            {
                p -= nums[l];
                l++;
            }
            else if(p + nums[r] == target)
            {
                //cout << r << endl;
                len = max(len, r-l+1);
                p += nums[r];
                r++;
            }
        }
        
        //cout << len << endl;
        if(len == 0) return -1;
        
        return n-len;
    }
};