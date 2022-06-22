class Solution {
public:
    
    int helper(int i, int j, string &str1, string &str2, vector <vector <int> >&dp)
    {
        if(i == str1.size() || j == str2.size())
        {
            dp[i][j] = 0;
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(str1[i] == str2[j])
        {
            return dp[i][j] = 1 + helper(i+1,j+1,str1,str2,dp);
        }
        else
        {
            return dp[i][j] = max(helper(i+1,j,str1,str2,dp), helper(i,j+1,str1,str2,dp));
        }
        
        return 1e9;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
            
        int n = str1.size();
        int m = str2.size();
        vector < vector <int> > memo(n+1,vector <int> (m+1,-1));
        int ans = helper(0,0,str1,str2,memo);
        
        // for(int i = 0; i <= n; i++)
        // {
        //     for(int j = 0; j <= m; j++)
        //     {
        //         cout << memo[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        string lcs = "";
        
        int i = 0, j = 0;
        
        while(i < n && j < m)
        {
            if(str1[i] == str2[j] && memo[i][j] == 1 + memo[i+1][j+1])
            {
                lcs += str1[i];
                i++,j++;
            }
            else if(memo[i][j] == memo[i+1][j])
            {
                i++;
            }
            else if(memo[i][j] == memo[i][j+1])
            {
                j++;
            }
        }
        
        string sup = "";
            
        int a = 0, b = 0;
        
        for(int i = 0; i < lcs.size(); i++)
        {
            while(lcs[i] != str1[a])
            {
                sup += str1[a++];
            }
            
            while(lcs[i] != str2[b])
            {
                sup += str2[b++];
            }
            
            sup += lcs[i];
            a++,b++;
        }
        
        return sup + str1.substr(a) + str2.substr(b);
        
    }
};