class Solution {
public:
    
    void dfs(vector <int> &vis, int src, vector<vector<int>>& mat)
    {
        vis[src] = 1;
        int n = mat.size();
        for(int i = 0; i < n; i++)
        {
            if(mat[src][i] && !vis[i])
            {
                dfs(vis,i,mat);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& mat) {
        
        int n = mat.size();
        
        vector <int> vis(n,0);
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                ans++;
                dfs(vis,i,mat);
            }
        }
        return ans;
    }
};