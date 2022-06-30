class Solution {
public:
    int memo[10][2][2][1024];
    int unique(string &s, int i, int f, int c, int mask)
    {
        if(i >= s.size())
        {
            if(c)
                return 1;
            return 0;
        }
        if(memo[i][f][c][mask] != -1) return memo[i][f][c][mask];
        int up = s[i] - '0';
        int ans = 0;
        
        if(f)
        {
            up = 9;
        }
        
        if(!c)
        {
            ans += unique(s,i+1,1,c,mask);
            
            for(int j = 1; j <= up; j++)
            {
                if(mask&(1<<j)) continue;
                ans += unique(s,i+1,f||(j < up),1,mask|(1<<j));
            }
        }
        else
        {
            for(int j = 0; j <= up; j++)
            {
                if(mask&(1<<j)) continue;
                ans += unique(s,i+1,f||(j < up),1,mask|(1<<j));
            }
        }
        return memo[i][f][c][mask] = ans;
    }
    
    int numDupDigitsAtMostN(int n) {
        
        string s = to_string(n);
        int mask = 0;
        memset(memo,-1,sizeof memo);
        int ans = unique(s,0,0,0,mask);
        return n - ans;
    }
};