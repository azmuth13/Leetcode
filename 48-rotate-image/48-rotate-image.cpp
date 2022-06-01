class Solution {
public:
    void rotate(vector<vector<int>>& A) {
        
        int n = A.size();

        // transpose
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                swap(A[i][j],A[j][i]);
            }
        }
        
        // for(int i = 0 ;i < n; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         cout << A[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        // reflect
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n/2; j++)
            {
                swap(A[i][j],A[i][n-j-1]);
            }
        }
        
        // for(int i = 0 ;i < n; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         cout << A[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
};