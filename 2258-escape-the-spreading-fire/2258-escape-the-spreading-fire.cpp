class Solution {
public:
    vector <int> dx,dy;
    bool valid(int i, int j, int n, int m)
    {
        return (i >=0 && i < n && j >=0 && j < m);
    }
    
    bool possible(int time, vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        
        queue <vector <int> > q;
        vector <vector <int> > visFire(n, vector <int>(m,0)), 
        visMe(n, vector<int>(m,0));
        
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push({i,j,1});
                    visFire[i][j] = 1;
                }
            }
        }
        
        if(time == 0)
        {
            q.push({0,0,0});
            visMe[0][0] = 1;
        }
        
        bool flag = 0;
        int inc = 1;
        while(!q.empty())
        {
            int sz = q.size();
            
            inc++;
            while(sz--)
            {
                auto v = q.front();
                q.pop();
                
                int type = v[2];
                int x = v[0];
                int y = v[1];

                if(x==n-1 && y==m-1 && type==0)
                {
                    return true;
                }
                
                for(int d = 0; d < 4; d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    if(valid(nx,ny,n,m) && grid[nx][ny] != 2)
                    {
                        if(type == 1)
                        {
                            if(!visFire[nx][ny])
                            {
                                visFire[nx][ny] = inc;
                                q.push({nx,ny,1});
                            }
                        }
                        else
                        {
                            if((visFire[nx][ny] == 0 || (visFire[nx][ny] >= inc && (nx==n-1 && ny == m-1)))
                               && !visMe[nx][ny])
                            {
                                visMe[nx][ny] = 1;
                                q.push({nx,ny,0});
                            }
                        }
                    }
                }
            }
            
            if(time==1 && !visMe[0][0])
            {
                q.push({0,0,0});
                visMe[0][0] = 1;
                flag = 1;
            }
            if(time >= 0)
            time--;
            
        }
        
        if(flag) return false;
        
        q.push({0,0});
        visMe[0][0] = 1;
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto v = q.front();
                q.pop();
                
                int x = v[0], y = v[1];
                if(x==n-1 && y==m-1)
                {
                    return true;
                }
                
                for(int d = 0; d < 4; d++)
                {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    if(valid(nx,ny,n,m) && grid[nx][ny] != 2)
                    {
                        if(!visFire[nx][ny] && !visMe[nx][ny])
                        {
                            visMe[nx][ny] = 1;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return false;
    }
    
    int maximumMinutes(vector<vector<int>>& grid) {

        int l = 0, r = 1e9;
        int ans = -1;
        dx = {-1,1,0,0};
        dy = {0,0,-1,1};
        

        while(l <= r)
        {
            int time = l + (r-l)/2;
            if(possible(time,grid))
            {
                ans = time;
                l = time+1;
            }
            else
            {
                r = time-1;
            }
        }
        
        //if(possible(0,))
        
        return ans;
    }
};