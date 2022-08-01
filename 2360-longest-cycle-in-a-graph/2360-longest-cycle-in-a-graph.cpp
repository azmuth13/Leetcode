class Solution {
public:
    int ans;
    void dfs(int src, vector <vector <int> > &adj, vector <int> &dis, vector <int> &currDis)
    {
        for(auto &neigh : adj[src])
        {
            if(currDis[neigh] != -1)
            {
                int prev = currDis[neigh];
                int now = 1 + currDis[src];
                ans = max(ans, now-prev);
            }
            else if(dis[neigh] == -1)
            {
                dis[neigh] = 1 + dis[src];
                currDis[neigh] = 1 + currDis[src];
                dfs(neigh, adj, dis,currDis);
            }
        }
        currDis[src] = -1;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        ans = -1;
        vector < vector <int> > adj(n);
        
        for(int i = 0; i < n; i++)
        {
            if(edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
        }
        
        vector <int> dis(n,-1), currDis(n,-1);
        for(int i = 0; i < n; i++)
        {
            if(dis[i] == -1)
            {
                currDis[i] = 0;
                dis[i] = 0;
                dfs(i,adj,dis, currDis);
            }
        }
        return ans;
    }
};