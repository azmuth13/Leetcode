class Solution {
public:
    int memo[1001][1001];
    int helper(string &s1, string &s2, int i, int j)
    {
        if(i == s1.size() && j == s2.size())
        {
            cout << "cnt" << endl;
            return 0;
        }
        
        if(i == s1.size())
        {
            int cnt = 0;
            for(int k = j; k < s2.size(); k++)
                cnt += s2[k];
            return cnt;
        }
        
        if(j == s2.size())
        {
            int cnt = 0;
            for(int k = i; k < s1.size(); k++)
                cnt += s1[k];
            
            return cnt;
        }
        
        if(memo[i][j] != -1) return memo[i][j];
        
        if(s1[i] == s2[j])
        {
            return memo[i][j] = helper(s1,s2,i+1,j+1);
        }
        
        return memo[i][j] = min(s1[i] + helper(s1,s2,i+1,j), s2[j] + helper(s1,s2,i,j+1));
        
    }
    
    int minimumDeleteSum(string s1, string s2) {
        memset(memo,-1,sizeof memo);
        int ans = helper(s1,s2,0,0);
        return ans;
    }
};