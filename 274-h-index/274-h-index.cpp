class Solution {
public:
    int hIndex(vector<int>& c) {
        
        // k1 + k2 - 1 = c.size()
        // update
        int n = c.size();
        if(n==1)
        {
            return (c[0] !=0);
        }
        int ans = 0;
        
        for(int h = 0; h <= n; h++)
        {
            int k1 = 0, k2 = 0, k3 = 0;
            
            for(int j = 0; j < n; j++)
            {
                if(c[j] > h)
                    k1++;
                else if(c[j] < h)
                    k2++;
                else
                    k3++;
            }
            
            if(k1+k2+k3 == n && k1+k3 >= h)
                ans = h;
            
        }
        
        return ans;
    }
};