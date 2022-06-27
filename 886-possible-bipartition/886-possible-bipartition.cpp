class Solution {
public:
    
    void dfs(vector<vector <int>>&adj, int src, int n, vector <int> &col, bool &res)
    {
        for(auto neigh : adj[src])
        {
            if(col[neigh] == -1)
            {
                col[neigh] = 1-col[src];
                dfs(adj,neigh,n,col,res);
            }
            else if(col[neigh] == col[src])
            {
                res = false;
                return;
            }
        }
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector < vector<int>> adj(n+1);
        for(auto x : dislikes)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        
        vector < int > col(n+1,-1);
        
        for(int i = 1; i <= n; i++)
        {
            if(col[i] == -1)
            {
                col[i] = 0;
                bool res = true;
                dfs(adj,i,n,col,res);
                if(res == false)
                    return false;
            }
        }
        
        return true;
    }
};