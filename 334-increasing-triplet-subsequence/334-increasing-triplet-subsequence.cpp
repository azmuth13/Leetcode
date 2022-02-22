class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        
        vector <int> g(n), s(n);
        
        s[0] = nums[0];
        
        for(int i = 1; i < n; i++)
        {
            s[i] = min(s[i-1], nums[i]);
        }
        
        g[n-1] = nums[n-1];
        
        for(int i = n-2; i >= 0; i--)
        {
            g[i] = max(g[i+1], nums[i]);
        }
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] < nums[i] && nums[i] < g[i])
                return true;
        }
        return false;
    }
};