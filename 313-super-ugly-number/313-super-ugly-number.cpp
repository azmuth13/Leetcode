class Solution {
public:

    
    using ll = long long;
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        ios_base::sync_with_stdio(0);cin.tie(0);
        
        priority_queue < pair<ll,ll>, vector <pair<ll,ll>> , greater <pair<ll,ll>> > pq;
        
        int sz = primes.size();
    
        vector <ll> v;
        v.push_back(1);
        vector <ll> p(sz,0);
        
        for(int i = 0; i < sz; i++)
        {
            pq.push({primes[i],i});
        }
        
        n--;
        while(n--)
        {
            ll nextugly = pq.top().first;
            
            v.push_back(nextugly);

            while(!pq.empty() && pq.top().first == nextugly)
            {
                ll ind = pq.top().second;
                pq.pop();
                
                p[ind]++;
                
                ll val = primes[ind]*(v[p[ind]]);
                
                pq.push({val,ind});
            }
        }
        
        return v.back();
    }
};