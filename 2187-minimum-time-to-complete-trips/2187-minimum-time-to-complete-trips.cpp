class Solution {
public:
    
    using ll = unsigned long long;
    
    bool okay(vector<int>& time, ll mid, ll tT)
    {
        ll trips = 0;
        
        for(auto &x : time)
        {
            trips += (mid/x);
        }
        
        return trips>=tT;
    }
    
    
    long long minimumTime(vector<int>& time, int tT) {
        
        ll ans = 0;
        
        ll l = 0;
        ll r = 1e16;
        
        while(l <= r)
        {
            ll mid = (l+r)/2;
            
            if(okay(time,mid,tT))
            {
                //cout << "Yes\n";
                ans = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        
        return ans;
    }
};