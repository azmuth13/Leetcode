class Solution {
public:
    
    bool check(int h, vector <int> &c)
    {
        int n = c.size();
        int val=0;
        for(int i = 0; i < n; i++)
        {
            if(c[i] >= h)
                val++;
        }
        return (val >= h);
    }
    
    int hIndex(vector<int>& c) {
        
        // k1 + k2 - 1 = c.size()
        // update
        int n = c.size();
        
        int ans = 0;
        
        int l = 0, r = n;
        
        while(l <= r)
        {
            int h = (l+r)/2;
            
            if(check(h,c))
            {
                ans = h;
                l = h+1;
            }
            else
            {
                r = h-1;
            }
        }
        return ans;
    }
};