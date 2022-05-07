class Solution {
public:
    
    int subarraysWithAtmostK(vector <int>& nums, int k)
    {
        int n = nums.size();
        int res = 0;
        
        int l = 0;
        int ans = 0;
        unordered_map <int, int> mp;
        
        int r = 0;
        int cnt = 0;
        
        while(r < n)
        {
            mp[nums[r]]++;
            
            if(mp[nums[r]] == 1)
                cnt++;
            r++;
            
            while(l < r && cnt > k)
            {
                mp[nums[l]]--;
                
                if(mp[nums[l]] == 0)
                    cnt--;
                
                l++;
            }
            
            res += (r-l);
        }
        
        return res;
        
    }
    
    int atmost(vector <int> &nums, int k)
    {
        int ans = 0;
        
        int n = nums.size();
        int l = 0, r = 0;
        
        map <int, int> mp;
        
        while(r < n)
        {
            mp[nums[r]]++;
            
            while(l <= r && mp.size() > k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                {
                    mp.erase(nums[l]);
                }
                l++;
            }
            
            ans += (r-l+1);
            r++;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        // int ans = subarraysWithAtmostK(nums, k) - 
        //     subarraysWithAtmostK(nums, k-1);
        return atmost(nums, k) - atmost(nums, k-1);
        //return ans;
    }
};
