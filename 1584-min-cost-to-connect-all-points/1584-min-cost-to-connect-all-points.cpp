class Solution {
public:
    
    // solve using kruskal
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        
        vector < pair <int, int> > adj[n];
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
    
                int wt = abs(points[i][0] - points[j][0]) + 
                    abs(points[i][1] - points[j][1]);
                
                adj[i].push_back({j, wt});
                adj[j].push_back({i, wt});
            }
        }
        
        int key[n];
        bool mstSet[n];
        int parent[n];
        
        for(int i = 0; i < n; i++)
        {
            key[i] = INT_MAX;
            mstSet[i] = false;
            parent[i] = -1;
        }
        
         key[0] = 0;
        
//         for(int count = 0; count < n-1; count++)
//         {
//             int mini = INT_MAX, u;
            
//             for(int v = 0; v < n; v++)
//             {
//                 if(mstSet[v] == false && key[v] < mini)
//                 {
//                     mini = key[v], u = v;
//                 }
//             }
            
//             mstSet[u] = true;
            
//             for(auto it : adj[u])
//             {
//                 int v = it.first;
//                 int wt = it.second;
                
//                 if(mstSet[v] == false && wt < key[v])
//                     parent[v] = u, key[v] = wt;
//             }
//         }
        priority_queue < pair <int, int>, vector < pair <int, int> >, greater <pair <int, int> > > pq;

        pq.push({0, 0});

        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            
            if(mstSet[u])
                continue;
            
            mstSet[u] = true;

            for(auto it : adj[u])
            {
                int v = it.first;
                int wt = it.second;

                if(mstSet[v] == false && wt < key[v])
                {
                    parent[v] = u;
                    key[v] = wt;
                    pq.push({key[v], v});
                }
            }
        }
        
        int ans = 0;
        
        for(int i = 1; i < n; i++)
        {
            int j = parent[i];
            
            int wt = abs(points[i][0] - points[j][0]) + 
                    abs(points[i][1] - points[j][1]);
            
            ans += key[i];
            
            //cout << i << " " << j << endl; 
        }
        return ans;
    }
};