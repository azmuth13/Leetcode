class Solution {
public:
    vector <char> v;
    int memo[51][6];
    int helper(int n, int ind)
    {
        if(n == 0) return 1;
        if(memo[n][ind] != -1) return memo[n][ind];
        int ans = 0;
        for(int i = ind; i < 5; i++)
        {
            ans += helper(n-1,i);
        }
        return memo[n][ind] = ans;
    }
    
    int countVowelStrings(int n) {
        v = {'a', 'e', 'i', 'o', 'u'};
        
        int ans = 0;
        memset(memo,-1,sizeof memo);
        for(int i = 0; i < 5; i++)
        {
            ans += helper(n-1,i);
        }
        
        return ans;
    }
};