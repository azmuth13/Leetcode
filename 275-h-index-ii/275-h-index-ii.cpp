class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size(),ans = n;
        int l = 0, r = n-1;
      
        while(l <= r)
        {
            int h = l + (r-l)/2;
            if(c[h] == n-h) return c[h];
            if(c[h] < n-h)
            {
                l = h+1;
            }
            else
            {
                ans = h;
                r = h-1;
            }
        }
        return n - ans;
    }
};