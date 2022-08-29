
 pair<int, int> dirs[] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
class Solution {
public:
    
   
    int m, n;
    
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& vis)
    {
        vis[i][j] = true;
        
        for(int k=0; k<4; k++)
        {
            int newi = i + dirs[k].first;
            int newj = j + dirs[k].second;
            
            if(newi < 0 || newi >= m || newj < 0 || newj >= n)
                continue;
            
            if(vis[newi][newj])
                continue;
            
            if(grid[newi][newj] == '0')
                continue;
            
            dfs(grid, newi, newj, vis);
        }
  
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        m = grid.size();
        
        n = grid[0].size();
        
        int count = 0;
        
        vector < vector <bool> > vis(m+1, vector <bool>(n+1, 0));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == false)
                {
                    count++;
                    dfs(grid, i, j, vis);
                }
            }
        }
        
        return count;
    }
};