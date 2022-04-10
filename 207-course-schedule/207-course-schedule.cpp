class Solution {
public:
    
    vector <int> ans;
    
    void dfs(int src, vector <int> adj[], vector <bool> &visited)
    {
        visited[src] = 1;
        
        for(int i=0; i<adj[src].size(); i++)
        {
            if(visited[adj[src][i]])
                continue;
            
            dfs(adj[src][i], adj, visited);
        }
        
        ans.push_back(src);
    }
    
    void topologicalSort(vector <int> adj[], int n, int e)
    {
        vector <bool> visited(n+1, false);
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
                dfs(i, adj, visited);
        }
        
        reverse(ans.begin(), ans.end());
    }
    
    bool check(int src, vector <int> adj[], vector<int> &vis)
    {
        vis[src] = 1;
        bool res = false;
        for(auto x : adj[src])
        {
            if(vis[x] == 1)
            {
                return true;
            }
            else if(vis[x] == 0)
            {
                res = res | check(x, adj, vis);
            }
        }
        
        vis[src] = 2;
        return res;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int e = prerequisites.size();
        vector <int> adj[numCourses];
        
        for(int i=0; i<e; i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            
            adj[u].push_back(v);
        }
        
        vector <int> vis(numCourses,0);
        for(int cr = 0; cr < numCourses; cr++)
        {
            if(!vis[cr])
            {
                bool cycle = check(cr, adj, vis);
                if(cycle)
                    return false;
            }
        }
        
        return true;
    }
};