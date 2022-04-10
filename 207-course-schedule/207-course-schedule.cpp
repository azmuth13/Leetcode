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
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int e = prerequisites.size();
        vector <int> adj[numCourses];
        
        for(int i=0; i<e; i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            
            adj[u].push_back(v);
        }
        
        topologicalSort(adj, numCourses, e);
        
        map <int, int> mp;
        
        for(int i = 0; i<ans.size(); i++)
        {
            mp[ans[i]] = i;
            //cout<<ans[i]<<" ";
        }
        //cout<<endl;
        
        
        for(int i=0; i<e; i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            
            if(mp[u] > mp[v] || u == v)
                return false;
        }
        
        return true;
    }
};