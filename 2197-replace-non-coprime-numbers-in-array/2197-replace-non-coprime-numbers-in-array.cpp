class Solution {
public:
    using ll = long long;
    
    ll LCM(ll a, ll b)
    {
        return (a*b)/(__gcd(a,b));
    }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        
        stack <ll> st;

        for(int i = 0; i < n; i++)
        {
            if(st.size() > 0 && __gcd((ll)st.top(), (ll)nums[i]) > 1ll)
            {
                ll val = nums[i];
                while(st.size() > 0 && __gcd((ll)st.top(), val) > 1ll)
                {
                    val = LCM(val, st.top());
                    st.pop();
                }
                st.push(val);
            }
            else
            {
                st.push(nums[i]);
            } 
        }
        
        while(st.size() > 0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
};