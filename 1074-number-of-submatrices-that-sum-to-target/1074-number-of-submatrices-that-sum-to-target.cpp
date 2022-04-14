class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        
        for(int l = 0; l < m; l++)
        {
            vector <int> v(n,0);
            for(int r = l; r < m; r++)
            {
                for(int i = 0; i < n; i++)
                {
                    v[i] += mat[i][r];
                }
                
                map <int, int> mp;
                mp[0] = 1;
                int running_sum = 0;
                
                for(int i = 0; i < n; i++)
                {
                    running_sum += v[i];
                    
                    ans += mp[running_sum - target];
                    
                    mp[running_sum]++;
                }
            }
        }
        return ans;
    }
};