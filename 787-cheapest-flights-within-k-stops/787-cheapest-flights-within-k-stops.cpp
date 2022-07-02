class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector <int> dis(n+1,1e9);
        dis[src] = 0;
        for(int i = 1; i <= k+1; i++)
        {
            vector <int> copy = dis;
            
            for(auto x : flights)
            {
                int u = x[0];
                int v = x[1];
                int w = x[2];
                if(dis[v] > copy[u] + w)
                    dis[v] = copy[u] + w;
            }
        }
        if(dis[dst] == 1e9)
            return -1;
        
        return dis[dst];
    }
};