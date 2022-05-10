class Solution {
public:
    using ll = long long;

    ll mod_pow(ll a,ll b,ll M)
    {
        if(a == 0) return 0;

        b %= (M - 1);

        ll res = 1;

        while(b > 0)
        {
            if(b&1) res=(res*a)%M;
            a=(a*a)%M;
            b>>=1;
        }

        return res;
    }
    int sumSubseqWidths(vector<int>& nums) {
        ll mod = 1e9 + 7;
        
        sort(nums.begin(), nums.end());
            
        ll ans = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            ll val = mod_pow(2,i,mod) - mod_pow(2,n-i-1,mod);
            val = (val*nums[i])%mod;
            ans += val;
            ans %= mod;
        }
        
        return (ans + mod) % mod;
    }
};