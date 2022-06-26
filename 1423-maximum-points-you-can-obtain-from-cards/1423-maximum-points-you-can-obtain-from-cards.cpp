class Solution {
public:
    int maxScore(vector<int>& cP, int k) {
        
        int ans = 0, sum = 0, n = cP.size();
        for(int i = 0; i < n; i++) sum += cP[i];
        
        int l = 0, r = 0;
        int tsum = 0;
        while(r < n-k)
        {
            tsum += cP[r++];
        }
        
        while(r < n)
        {
            ans = max(ans, sum - tsum);
            tsum -= cP[l];
            tsum += cP[r];
            l++, r++;
        }
        ans = max(ans, sum - tsum);
        return ans;
    }
};