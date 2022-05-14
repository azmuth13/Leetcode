class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector <int> R(n+1,0);
        
        for(int i = 0; i <= n; i++)
        {
            int l = i - ranges[i];
            int r = i + ranges[i];
            
            if(l < 0)
                l = 0;
            R[l] = max(R[l], r);
        }
        
        int i=0, end = 0, farthest = 0;
        int ans = 0;
        while(i <= n && end < n)
        {
            ans++;
            
            while(i <= end && end < n)
            {
                farthest = max(farthest, R[i]);
                i++;
            }
            
            if(end == farthest)
                return -1;
            
            end = farthest;
            
        }
        return ans;
    }
};