class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        
        int l = 1;
        int r = m*n;
        int ans = -1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            
            int count = 0;
            int j = n;
            for(int i = 1; i <= m; i++)
            {
                while(j >= 1 && i*j > mid)
                {
                    j--;
                }
                count += j;
            }
            if(count < k)
            {
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