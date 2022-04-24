class Solution {
public:
    
    void dfsHelper(vector<vector<int>>& edges, int &res, int src, vector <int> &vis)
    {
        vis[src] = 1;
        res++;
        
        for(int j = 0; j < edges[src].size(); j++)
        {
            if(!vis[edges[src][j]])
            {
                dfsHelper(edges, res, edges[src][j], vis);
            }
        }
    }
    
    void dfs(vector<vector<int>>& ed, int &res, int i)
    {
        int n = ed.size();
        
        vector < vector <int> > edges(n+1);
        
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                continue;
            
            edges[ed[j][0]].push_back(ed[j][1]);
            edges[ed[j][1]].push_back(ed[j][0]);
        }
        
        vector <int> vis(n+1, 0);
        
        dfsHelper(edges, res, 1, vis);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& ed) {
        
        int n = ed.size();
        
        for(int i = n-1; i>=0; i--)
        {
            int res = 0;
            
            dfs(ed, res, i);
            
            if(res == n)
                return ed[i];
        }
        
        return {};
    }
};