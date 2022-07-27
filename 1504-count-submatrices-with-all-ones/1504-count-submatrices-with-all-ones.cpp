class Solution {
public:
    int fun(vector <int> &v)
    {
        int res = 0, len = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] == 0)
            {
                res += len*(len+1)/2;
                len = 0;
            }
            else
            {
                len++;
            }
        }
        res += len*(len+1)/2;
        return res;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {   
            vector <int> v(m,1);
            for(int j = i; j < n; j++)
            {
                for(int k = 0; k < m; k++)
                {
                    v[k] = v[k]&mat[j][k];
                }
                
                ans += fun(v);
            }
        }
        return ans;
    }
};