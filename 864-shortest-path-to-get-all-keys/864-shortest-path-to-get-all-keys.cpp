class Solution {
public:
    #define print(a) for (auto x : a) cout << x << " "; cout << endl
    
    int count(vector<string>& grid)
    {
        int ans = 0;
        
        for(auto &x : grid)
        {
            for(auto &y : x)
            {
                ans += (y >= 'a' && y <= 'z');
            }
        }
        
        return ans;
    }
    
    int shortestPathAllKeys(vector<string>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int vis[32][32][65];
        
        for(int i = 0; i < 32; i++)
        {
            for(int j = 0; j < 32; j++)
            {
                for(int k = 0; k < 65; k++)
                {
                    vis[i][j][k] = 0;
                }
            }
        }
        
        int keys = count(grid);
        
        int sx = 0, sy = 0;
        
        for(int i = 0; i < n; i++)
        {
            bool flag = 0;
            
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '@')
                {
                    sx = i;
                    sy = j;
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        int dir1[] = {-1, 1, 0, 0};
        int dir2[] = {0, 0, -1, 1};
        
        queue < vector <int> > q;
        //   x, y, keys, set steps
        
        q.push({sx, sy, 0, 0, 0});
        
        int ans = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            
            while(sz--)
            {
                auto v = q.front();
                q.pop();
                
                int x = v[0];
                int y = v[1];
                int keysYet = v[2];
                int set = v[3];
                
                if(vis[x][y][set] == 1)
                {
                    continue;
                }
                
                if(keysYet == keys)
                {
                    //print(v);
                    return v[4];
                }

                vis[x][y][set] = 1;
                
                //print(v);
                
                for(int h = 0; h < 4; h++)
                {
                    int nx = x + dir1[h];
                    int ny = y + dir2[h];
                    
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m
                       || grid[nx][ny] == '#')
                    {
                        continue;
                    }
                
                    if(grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z')
                    {
                        int num = grid[nx][ny] - 'a';
                        bool f = !(set & (1 << num));
                        if(!vis[nx][ny][set | (1 << num)])
                            q.push({nx, ny, keysYet + f, set|(1<<num), v[4]+1});
                        
                    }
                    else if(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z')
                    {
                        int num = grid[nx][ny] - 'A';
                
                        if(set & (1<<num) && !vis[nx][ny][set])
                        {
                            q.push({nx,ny, keysYet, set, v[4] + 1});
                        }
                    }
                    else
                    {
                        if(!vis[nx][ny][set])
                            q.push({nx,ny,keysYet,set, v[4] + 1});
                    }
                }
            }
            
            ans++;
        }
        
        return -1;
    }
};