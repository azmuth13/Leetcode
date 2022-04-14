class Solution {
public:
    
    int maxSumSubmatrix(vector<vector<int>>& mat, int target) {
        
        int n = mat.size();
        int m = mat[0].size();
        
        int ans = -1e9;
        
        for(int j = 0; j < m; j++)
        {
            vector <int> sum(n,0);
            
            for(int k = j; k < m; k++)
            {
                for(int i = 0; i < n; i++)
                {
                    sum[i] += mat[i][k];
                }
                
                set <int> st;
                st.insert(0);
                int curr = 0;
                
                for(int i = 0; i < n; i++)
                {
                    curr += sum[i];
                    
                    auto it = st.lower_bound(curr - target);
                    
                    if(it != st.end())
                    {
                        ans = max(ans, curr - *it);
                    }
                    st.insert(curr);
                }
            }
        }
        
        return ans;
    }

};