class Solution {
public:
    int memo[32][2][2];
    int helper(string &s, int i, int f, int prev)
    {
        if(i >= s.size())
        {
            return 1;
        }
        
        if(memo[i][f][prev] != -1) return memo[i][f][prev];
        
        int up = s[i] - '0';
        
        if(f)
            up = 1;
        
        
        int ans = 0;
        
        for(int j = 0; j <= up; j++)
        {
            if(prev!= 1 || j != 1)
            ans += helper(s,i+1,f||(j < up),j);
        }

        return memo[i][f][prev] = ans;
    }
    
    //4241234
    
    int findIntegers(int n) {
        string s = "";
        
        while(n > 0)
        {
            s += ('0' + (n%2));
            n/=2;
        }
        
        reverse(s.begin(),s.end());
        memset(memo,-1,sizeof memo);
        int ans = helper(s,0,0,0);
        
        return ans;
    }
};
