class Solution {
public:
    
    bool dfs(int src, vector < vector <int> > &adj, vector <int> &vis, vector <int> &dfsVis)
    {
        vis[src] = 1;
        dfsVis[src] = 1;
        
        for(auto &neigh : adj[src])
        {
            if(!vis[neigh])
            {
                if(dfs(neigh,adj,vis,dfsVis))
                    return true;
            }
            else if(dfsVis[neigh])
            {
                
                return true;
            }
                
        }
        
        dfsVis[src] = 0;
        return false;
    }
    
    bool cycle(vector <vector <int>> &adj, int n)
    {
        vector <int> vis(n+1,0);
        vector <int> dfsVis(n+1,0);
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                 if(dfs(i,adj,vis,dfsVis))
                    return true;
            }
               
        }
        
        return false;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int m = edges.size();
            
        int n = colors.size();
        vector < vector <int> > count(n, vector <int>(26,0));
        
        vector <vector <int> > adj(n+1);
        vector <int> indeg(n+1,0);
        for(int i = 0; i < m; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            indeg[edges[i][1]]++;
        }
        
        if(cycle(adj,n))
            return -1;

        queue < int > q;
        
        for(int i = 0; i < n; i++)
        {
            if(indeg[i])
                continue;
            q.push(i);
        }
        int ans = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                int node = q.front();
                q.pop();
                
                count[node][colors[node]-'a']++;
                ans = max(ans, count[node][colors[node]-'a']);
 
                for(auto &x : adj[node])
                {
                    indeg[x]--;
                    if(indeg[x] == 0)
                        q.push(x);
                    
                    for(int i = 0; i < 26; i++)
                    {
                        count[x][i] = max(count[x][i],count[node][i]);
                    }
                }
            }
        }
        return ans;
    }
};