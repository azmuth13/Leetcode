class Solution {
public:
    using ll = long long;
    
    void dijkstra(ll src, vector <ll> &d, vector < pair <ll, ll> >adj[100005])
    {
        priority_queue < pair <ll, ll>, vector <pair <ll, ll> >, greater <pair <ll, ll>> > pq;
        
        pq.push({0, src});
        
        while(!pq.empty())
        {
            auto pp = pq.top();
            pq.pop();
            
            ll curr = pp.second;
            ll currCost = pp.first;
            
            if(currCost != d[curr])
                continue;
            
            for(auto x : adj[curr])
            {
                if(d[x.first] > d[curr] + x.second)
                {
                    d[x.first] = d[curr] + x.second;
                    pq.push({d[x.first], x.first});
                }
            }
            
        }
        
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
            
        vector < pair <ll,ll> > front[100005], back[100005];
        
        for(int i = 0; i < edges.size(); i++)
        {
            front[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            back[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        vector <ll> ds1(n+1, 1e15), ds2(n+1, 1e15), dd(n+1, 1e15);
        
        ds1[src1] = ds2[src2] = dd[dest] = 0;
        
        dijkstra(src1, ds1, front);
        dijkstra(src2, ds2, front);
        dijkstra(dest, dd, back);
        
//         if(dd[src1] == 1e15 || dd[src2] == 1e15)
//             return -1;
        
        ll ans = 1e15;
        
        for(int i = 0; i < n; i++)
        {
            ans = min(ans, ds1[i] + ds2[i] + dd[i]);
        }
        
        if(ans == 1e15)
            return -1;
        
        return ans;
    }
};