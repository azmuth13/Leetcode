class Solution {
public:
    
    int countFOranges(vector <vector <int> > &grid)
    {
        int cnt = 0;
        for(auto &row : grid)
        {
            for(auto &column : row)
            {
                cnt += (column == 1);
            }
        }
        return cnt;
    }
    
    bool valid(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >=0 && j < m);
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n, m;
        n = grid.size(), m = grid[0].size();
        vector < vector <int> > vis(n, vector <int>(m,0));
        queue < pair <int, int> > q;
        
        int cnt = countFOranges(grid);
        if(cnt == 0) return 0;
        //cout << cnt << endl;
        for(int i= 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        
        int minutes = 1;
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                pair <int, int> rot = q.front();
                q.pop();
                 
                for(int d = 0; d < 4; d++)
                {
                    int ni = rot.first + dx[d];
                    int nj = rot.second + dy[d];
                    
                    if(valid(ni,nj,n,m) && !vis[ni][nj] && grid[ni][nj] == 1)
                    {
                       
                        cnt--;
                        if(cnt <= 0)
                            return minutes;
                        
                        vis[ni][nj] = 1;
                        q.push({ni,nj});
                    }
                }
            }
            minutes++;
        }
        return -1;
    }
};