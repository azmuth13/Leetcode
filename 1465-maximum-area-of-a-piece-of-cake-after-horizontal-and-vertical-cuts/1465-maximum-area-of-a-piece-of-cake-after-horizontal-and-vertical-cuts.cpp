class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        int mod = 1e9 + 7;
        
        sort(hC.begin(),hC.end());
        sort(vC.begin(),vC.end());
        
        long long int H = hC[0];
        for(int i = 1; i < hC.size(); i++)
            H = max(H,(long long)(hC[i]-hC[i-1]));
        H = max(H,(long long)(h-hC.back()));
        
        long long int V = vC[0];
        for(int i = 1; i < vC.size(); i++)
            V = max(V,(long long)(vC[i]-vC[i-1]));
        V = max(V,(long long)(w-vC.back()));
        long long int ans = (V%mod * H%mod)%mod;
        return ans;
    }
};