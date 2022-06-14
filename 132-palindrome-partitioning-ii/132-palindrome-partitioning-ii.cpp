class Solution {
public:
    
    bool isPal(string &s, int i, int j)
    {
        
        while(i < j)
        {
            
            if(s[i] != s[j])
            {
                return false;
            }
            
            i++,j--;
        }
        return true;
    }
    
    
    int helper(string &s, int i, int *memo)
    {
        if(i >= s.size())
            return 0;
        
        if(memo[i] != -1)
            return memo[i];
        
        int ans = 1e9;
        
        for(int j = i; j < s.size(); j++)
        {
            if(isPal(s,i,j))
            {
                if(j != (s.size()-1))
                {
                    ans = min(ans, 1 + helper(s,j+1,memo));
                }
                else
                {
                    ans = min(ans, helper(s,j+1,memo));
                }
            }
        }
        return memo[i] = ans;
    }
    
    int minCut(string s) {
        int n = s.size();
        
        
        // bool ** storePal = new bool*[n+1];
        // for(int i=0; i <= n; i++)
        // {
        //     storePal[i] = new bool[n+1];
        //     for(int j = 0; j <= n; j++)
        //     {
        //         storePal[i][j] = 0;
        //     }
        // }
        
        if(isPal(s,0,n-1))
            return 0;
        
        int * memo = new int[n+1];
        for(int i = 0; i <= n; i++)
        {
            memo[i] = -1;
        }
        
        int ans = helper(s, 0, memo);
        return ans;
        
    }
};