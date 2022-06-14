class Solution {
public:
    int getVal(string &s, int i, int j)
    {
        int cnt = 0;
        while(i < j)
        {
            if(s[i] != s[j])
            {
                cnt++;
            }
            i++,j--;
        }
        return cnt;
    }
    
    int helper(string &s ,int k, int i, int ** memo)
    {
        if(k == 0)
        {
            return getVal(s,i,s.size()-1);
        }
        
        if(memo[i][k] != -1)
            return memo[i][k];
        
        int ans = 1e9;
        
        for(int j = i; j < s.size()-1; j++)
        {
            ans = min(ans, getVal(s,i,j) + helper(s,k-1,j+1, memo));
        }
        return memo[i][k] = ans;
    }
    
    int palindromePartition(string s, int k) {
        int n = s.size();
        
        int ** memo = new int*[n+1];
        
        for(int i = 0; i<= n; i++)
        {
            memo[i] = new int[n+1];
            for(int j = 0; j <= n; j++)
            {
                memo[i][j] = -1;
            }
        }
        
        int ans = helper(s, k-1, 0, memo);
        return ans;
    }
};