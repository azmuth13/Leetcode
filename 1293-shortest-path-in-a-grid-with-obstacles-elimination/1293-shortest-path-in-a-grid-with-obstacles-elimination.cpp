class Solution {
public:
    bool good(int x, int y, int n, int m)
    {
        return (x>=0 && x < n && y >=0 && y < m);
    }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        queue <vector <int>> q;
        vector < vector <int> > vis(n, vector <int>(m,-1));
        
        q.push({0,0,0,k});
        
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto vv = q.front();
                q.pop();
                
                int x = vv[0], y = vv[1], steps = vv[2],ele = vv[3];
                
                if(!good(x,y,n,m))
                    continue;
                
                if(x==n-1 && y==m-1)return steps;
                
                if(grid[x][y] == 1)
                {
                    if(ele >= 1)
                        ele--;
                    else
                        continue;
                }
                
                if(vis[x][y] != -1 && vis[x][y] >= ele)
                    continue;
                
                vis[x][y] = ele;
                
                for(int d = 0; d < 4; d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    q.push({nx,ny,steps+1,ele});
                }
            }
        }
        
        return -1;
    }
};

