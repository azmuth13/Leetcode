class Solution {
public:
    
    bool dfs(vector < vector <int> > &adj, vector <int> &vis, vector <int> &dfsVis, int i, vector <int> &ans)
    {
        
        vis[i] = 1;
        dfsVis[i] = 1;

        for(auto &neigh : adj[i])
        {
            if(!vis[neigh])
            {
                if(dfs(adj,vis,dfsVis,neigh,ans))
                {
                    return true;
                }
            }
            else if(dfsVis[neigh])
            {
                return true;
            }
        }
        
        ans[i] = 1;
        dfsVis[i] = 0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int A = adj.size();
        vector <int> vis(A+1,0);
        vector <int> dfsVis(A+1,0);
        vector <int> ans(A+1,0);
        for(int i = 0; i < A; i++)
        {
            if(!vis[i])
            {
                bool res = dfs(adj, vis, dfsVis, i, ans);
            }
        }
        vector <int> res;
        for(int i = 0; i < A; i++)
        {
            if(ans[i])
            {
                res.push_back(i);
            }
        }
        return res;
    }
};