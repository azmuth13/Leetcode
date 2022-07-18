class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        vector <int> lisL(n,0), lisR(n,0);
        vector <int> lis;
        for(int i = 0; i < n; i++)
        {
            auto it = lower_bound(lis.begin(),lis.end(),nums[i]);
            if(it == lis.end())
            {
                lis.push_back(nums[i]);
            }
            else
            {
                *it = nums[i];
            }
            lisL[i] = lis.size()-1;
        }
        lis.clear();
        for(int i = n-1; i >=0; i--)
        {
            auto it = lower_bound(lis.begin(),lis.end(),nums[i]);
            if(it == lis.end())
            {
                lis.push_back(nums[i]);
            }
            else
            {
                *it = nums[i];
            }
            lisR[i] = lis.size()-1;
        }
        int ans = 0;
        for(int i = 1; i < n-1; i++)
        {
            if(lisL[i]==0 || lisR[i]==0)
                continue;
            ans = max(ans, lisL[i] + lisR[i] + 1);
        }
        return n - ans;
    }
};