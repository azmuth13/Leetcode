class Solution {
public:
    
    using ll = long long;
    long long appealSum(string s) {
        
        ll ans = 0;
        ll n = s.size();
        for(char ch = 'a'; ch <= 'z'; ch++)
        {
            ll res = 0;
            ll cnt = 0;
            
            for(int i = 0; i < n; i++)
            {
                if(s[i] != ch)
                {
                    cnt++;
                }
                else
                {
                    ll val = cnt*(cnt+1)/2;
                    res += val;
                    cnt = 0;
                }
            }
            
            ll val = cnt*(cnt+1)/2;
            res += val;
            
            ll superVal = n*(n+1)/2;
            cout << superVal - res << endl;
            ans += superVal - res;
        }
        
        return ans;
    }
};