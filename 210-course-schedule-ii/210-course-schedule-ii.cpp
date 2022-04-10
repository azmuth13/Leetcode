class Solution {
public:
    
    vector <int> ans;
    void dfs(vector <int> adj[], int src, vector <int> &vis)
    {
        vis[src] = 1;
        
        for(auto &x : adj[src])
        {
            if(!vis[x])
                dfs(adj, x, vis);
        }
        ans.push_back(src);
    }
    
    void toposort(vector <int> adj[], int n, int e)
    {
        vector <int> vis(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                dfs(adj, i, vis);
            }
        }
        reverse(ans.begin(), ans.end());
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int e = prerequisites.size();
        vector <int> adj[numCourses];
        
        for(int i=0; i<e; i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            
            adj[u].push_back(v);
        }
        
        toposort(adj, numCourses, e);
        
        map <int, int> mp;
        
        for(int i = 0; i < ans.size(); i++)
        {
            mp[ans[i]] = i;
        }
        
        for(int i = 0; i < e; i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            
            if(mp[u] > mp[v] || u == v)
                return {};
        }
        
        return ans;
    }
};