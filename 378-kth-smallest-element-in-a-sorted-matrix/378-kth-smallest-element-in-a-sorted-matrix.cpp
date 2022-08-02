class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        
        int ans;
        int n = mat.size();
        
        int l = mat[0][0];
        int r = mat[n-1][n-1];
        
        while(l <= r)
        {
            int mid = l + (r-l)/2;
           // cout << mid << endl;
            int count = 0;
            int j = n-1;
            int ecnt = 0;
            for(int i = 0; i < n; i++)
            {
                while(j >= 0 && mat[i][j] > mid)
                {
                    j--;
                }
                count += (j+1);
            }
            if(count < k)
            {
                // ans = m;
                l = mid+1;
            }
            else
            {
                ans = mid;
                r = mid-1;
            }
        }
        return ans;
    }
};