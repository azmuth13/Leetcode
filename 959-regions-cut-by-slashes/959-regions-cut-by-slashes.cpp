int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
class Solution {
public:
    
    
    bool good(int i, int j, int n)
    {
        return (i >=0 && i < n && j >= 0 && j < n);
    }
    
    void dfs(vector<vector <int> >&mat, int i, int j)
    {
        mat[i][j] = -1;
        int sz = mat.size();
        for(int d = 0; d < 4; d++)
        {
            int ni = i+dx[d];
            int nj = j+dy[d];
            
            if(good(ni,nj,sz) && mat[ni][nj] == 0)
                dfs(mat,ni,nj);
        }
        
    }
    
    int regionsBySlashes(vector<string>& grid) {

        int n = grid.size();
        
        vector < vector <int> > mat(n*3, vector <int>(n*3,0));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == '/')
                {
                    mat[i*3][j*3+2] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3] = 1;
                }
                else if(grid[i][j] == '\\')
                {
                    mat[i*3][j*3] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3+2] = 1;
                }
            }
        }
        int ans = 0;
        
        for(int i = 0; i < 3*n; i++)
        {
            for(int j = 0; j < 3*n; j++)
            {
                if(mat[i][j] == 0)
                {
                    ans++;
                    dfs(mat,i,j);
                }
            }
        }
        
        return ans;
        
    }
};