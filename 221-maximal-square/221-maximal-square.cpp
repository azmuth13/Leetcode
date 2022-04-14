class Solution {
public:
    int histogram(vector <int> &heights)
    {
        int n = heights.size();
//         if(n == 1)
//             return heights[0];
        
        int ans = 0;
        
        vector <int> chotaPeeche(n,-1);
        vector <int> chotaAage(n,n);
        
        stack <int> stk;
        
        for(int i = n-1; i >= 0; i--)
        {
            while(stk.size() > 0 &&  heights[stk.top()] >= heights[i])
            {
                stk.pop();
            }
            
            if(stk.size() != 0)
            {
                chotaAage[i] = stk.top();
            }
            
            stk.push(i);
        }
        
        //reverse(heights.begin(), heights.end());
        
        stack <int> stk1;
        
        for(int i = 0; i < n; i++)
        {
            while(stk1.size() > 0 && heights[stk1.top()] >= heights[i])
            {
                stk1.pop();
            }
            
            if(stk1.size() != 0)
            {
                chotaPeeche[i] = stk1.top();
            }
            
            stk1.push(i);
        }
        
        // for(int i =0 ; i < n; i++)
        // {
        //     cout << chotaAage[i] << " ";
        // }
        // cout << endl;
        // for(int i =0 ; i < n; i++)
        // {
        //     cout << chotaPeeche[i] << " ";
        // }
        // cout << endl;
        
        
        //reverse(heights.begin(), heights.end());
        
        for(int i = 0; i < n; i++)
        {
            int len = (chotaAage[i] - 1) - (chotaPeeche[i]);
            
            if(len >= heights[i])
            {
                //cout << ans << endl;
                ans = max(ans, heights[i]*heights[i]);
            }
            
            
           // cout << ans << endl;
        }
        
        //cout << ans << endl;
        return ans;
    }
    int maximalSquare(vector<vector<char>>& mati) {
        
//     int m = matrix.size();
//     int n = matrix[0].size();
//     int len = 0;
        
//     vector <vector <int> > dp (m+1, vector <int> (n+1, 0));

//     for(int i = 1; i <= m; i++)
//     {
//         for(int j = 1; j <= n; j++)
//         {
//             if(matrix[i-1][j-1] == '0')
//             {
//                 dp[i][j] = 0;
//             }
//             else
//             {
//                 dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
//             }
//             len = max(len, dp[i][j]);
//         }
//     }
        
//     return len*len;
        int n = mati.size();
        int m = mati[0].size();
        vector < vector <int> > mat(n, vector <int>(m,0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                mat[i][j] = mati[i][j] - '0';
                //cout << mat[i][j] << " ";
            }
            //cout << endl;
        }
        
        for(int j = 0; j < m; j++)
        {
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                if(mat[i][j] == 1)
                {
                    sum += mat[i][j];
                    mat[i][j] = sum;
                }
                else
                {
                    sum = 0;
                }
            }
        }

        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            vector <int> v = mat[i];
            int res = histogram(v);
           // cout << res << endl;
            ans = max(ans, res);
        }
        return ans;
    }
};