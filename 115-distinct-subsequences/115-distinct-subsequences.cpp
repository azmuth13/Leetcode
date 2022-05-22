class Solution {
public:
    int memo[1001][1001];
    int helper(string &s, string &t, int i, int j)
    {
        if(j == t.size())
            return 1;
        if(i >= s.size())
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        int ans = 0;
        if(s[i] == t[j])
        {
            ans = helper(s,t,i+1,j) + helper(s,t,i+1,j+1);
        }
        else
        {
            ans = helper(s,t,i+1,j);
        }
        return memo[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        memset(memo,-1,sizeof memo);
        int ans = helper(s,t,0,0);
        return ans;
    }
};