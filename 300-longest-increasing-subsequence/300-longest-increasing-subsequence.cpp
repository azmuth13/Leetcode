class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        
        
        int n = nums.size();
            
//         vector <int> pref(n,1);
        
//         for(int i = 0; i<n; i++)
//         {
//             for(int j = i-1; j >= 0; j--)
//             {
//                 if(nums[j] < nums[i])
//                     pref[i] = max(pref[i], pref[j] + 1);
//             }
//         }
        
//         int ans = *max_element(pref.begin(), pref.end());
        
        vector <int> v;
        
        for(auto p : nums)
        {
            auto it = lower_bound(v.begin(), v.end(), p);
            
            if(it == v.end())
            {
                v.push_back(p);
            }
            else
            {
                *it = p;
            }
        }
        return v.size();
    }
};