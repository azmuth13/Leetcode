class Solution {
public:
    using ll = long long;
    
    long long wonderfulSubstrings(string word) {
        
        ll n = word.size();
        ll ans = 0;
        
        ll hash = 0;
        unordered_map <ll, ll> mp;
        mp[0] = 1;
        for(int i = 0; i < n; i++)
        {
            hash = hash ^ (1ll << (word[i] - 'a'));
            
            ans += mp[hash];
            
            for(int k = 0; k < 10; k++)
            {
                ll nhash = hash ^ (1ll<<(k));
                ans += mp[nhash];
            }
            
            mp[hash]++;
        }
        return ans;
    }
};