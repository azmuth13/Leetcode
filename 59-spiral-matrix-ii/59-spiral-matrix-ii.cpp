class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        
        vector <vector <int> > ans(n, vector <int>(n));
        
        int l = 0, u = 0, d = 0, r = 1;
        
        int num = 1;
        
        int row = 0, col = 0;
        int U = 0, L = -1, D = n, R = n;
        
        int pp = n*n;
        while(pp--)
        {
            if(r)
            {
                ans[row][col] = num;
                num++;
                col++;
                
                if(col == R)
                {
                    r = 0;
                    d = 1;
                    col-=1;
                    row++;
                    R--;
                }
            }
            else if(d)
            {
                ans[row][col] = num;
                num++;
                row++;
                
                if(row == D)
                {
                    d = 0;
                    l = 1;
                    col--;
                    row--;
                    D--;
                }
            }
            else if(l)
            {
                ans[row][col] = num;
                num++;
                col--;
                
                if(col == L)
                {
                    l = 0;
                    u = 1;
                    col++;
                    row--;
                    L++;
                }
            }
            else if(u)
            {
                ans[row][col] = num;
                num++;
                row--;
                
                if(row == U)
                {
                    row++;
                    u = 0;
                    r = 1;
                    col++;
                    U++;
                }
            }
        }
        
        return ans;
    }
};