class Solution {
public:
    int mod = 1e9 + 7;
    vector <int> lps;
    int memo[501][51][2][2];
    void fillLps(string &evil)
    {
        int sz = evil.size();
        int i = 0, j = 1;
        while(j < sz)
        {
            if(evil[i] == evil[j])
            {
                lps[j] = i+1;
                i++,j++;
            }
            else
            {
                if(i==0)
                {
                    lps[j] = 0;
                    j++;
                }
                else
                {
                    i = lps[i-1];
                }
            }
        }
    }
    
    int helper(string &s1, string &s2, string &evil, int i, int ei, int down, int up)
    {
        if(ei >= evil.size()) return 0;
        
        if(i >= s1.size())
        {
            return 1;
        }
        if(memo[i][ei][down][up] != -1) return memo[i][ei][down][up];
        int low = 'a';
        int high = 'z';
        
        if(!down)
        {
            low = s1[i];
        }
        
        if(!up)
        {
            high = s2[i];
        }
        
        int ans = 0;
        
        for(char ch = low; ch <= high; ch++)
        {
            int j = ei;
            while(evil[j] != ch && j >= 1) j = lps[j-1];
            
            ans += helper(s1,s2,evil,i+1, (ch==evil[j])?j+1:0, down||(ch > low), up||(ch < high));
            ans %= mod;
        }
        return memo[i][ei][down][up] = ans;
    }
    
    int findGoodStrings(int n, string s1, string s2, string evil) {
        
        int sz = evil.size();
        lps.resize(sz+1,0);
        fillLps(evil);
        memset(memo,-1,sizeof memo);
        int ans = helper(s1,s2,evil,0,0,0,0);
        return ans;
    }
};