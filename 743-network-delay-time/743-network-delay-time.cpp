class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int ans = -1;
        
        vector < pair <int, int> > adj[n+1];
        
        int sz = times.size();
        
        for(int i = 0; i<sz; i++)
        {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        vector <int> distance(n+1, INT_MAX);
        
        distance[k] = 0;
        
        // Priority queue
        
        priority_queue < pair <int, int> , vector < pair <int, int> > , greater < pair <int, int>> > pq;
        
        pq.push({0, k});
            
        while(!pq.empty())
        {
            pair <int, int> ptop = pq.top();
            pq.pop();
            
            int wt = ptop.first;
            int u = ptop.second;
            
            if(distance[u] != wt)
                continue;
            
            for(auto it : adj[u])
            {
                int v = it.first;
                int weight = it.second;
                
                if(distance[v] > distance[u] + weight)
                {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }
        
        for(int i = 1; i<=n; i++)
        {
            ans = max(ans, distance[i]);
        }
        
        if(ans == INT_MAX)
            return -1;
        
        return ans;
        
    }
};