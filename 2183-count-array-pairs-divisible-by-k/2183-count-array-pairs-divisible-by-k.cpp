class Solution {
public:
    using ll = long long;
    long long countPairs(vector<int>& nums, int k) {
        
        unordered_map <ll, ll> mp;
        
        int n = nums.size();
        ll ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            int gcd = __gcd(nums[i],k);
            
            for(auto x : mp)
            {
                if((x.first*gcd)%k==0)
                    ans += x.second;
            }
            
            mp[gcd]++;
        }
        
        return ans;
    }
};