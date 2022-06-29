class Solution {
public:
    
    bool good(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >=0 && j < m);
    }
    
    void dfs(int i, int j, vector<vector<int>>& grid2, vector<vector<int>>& grid1,
            bool &res)
    {
        int n = grid1.size();
        int m = grid1[0].size();
        
        if(grid2[i][j] == 1 && grid1[i][j] != 1)
        {
            res = false;
        }
        
        grid2[i][j] = 2;
        
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        
        for(int d = 0; d < 4; d++)
        {
            int ni = i + dx[d];
            int nj = j + dy[d];
            
            if(good(ni,nj,n,m) && (grid2[ni][nj]==1))
                dfs(ni,nj,grid2,grid1,res);
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid2[i][j] == 1)
                {
                    bool res = true;
                    dfs(i,j,grid2,grid1,res);
                    if(res) ans++;
                }
            }
        }
        return ans;
    }
};