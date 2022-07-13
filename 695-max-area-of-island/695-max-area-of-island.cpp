class Solution {
public:
    vector <int> dx,dy;
    bool valid(int i, int j, int n, int m)
    {
        return (i >=0 && i < n && j >= 0 && j < m);
    }
    void dfs(vector <vector <int> > &grid, int i, int j, int &curr)
    {
        grid[i][j] = 2;
        int n = grid.size();
        int m = grid[0].size();
        for(int d = 0; d < 4; d++)
        {
            int ni = i + dx[d];
            int nj = j + dy[d];
            
            if(valid(ni,nj,n,m) && grid[ni][nj]==1)
            {
                curr++;
                dfs(grid,ni,nj,curr);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dx = {-1,1,0,0};
        dy = {0,0,-1,1};
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j]==1)
                {
                    int curr = 1;
                    dfs(grid,i,j,curr);
                    ans = max(ans, curr);
                }
            }
        }
        return ans;
    }
};