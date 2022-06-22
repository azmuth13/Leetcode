class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        // shortest commom supersequence : all of the str1  + all of the str2 - Longest common subsequence between str1 and str2
        int n = str1.size();
        int m = str2.size();
        vector < vector <int> > dp(n+1, vector <int>(m+1,0));
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        
//         for(int i = 0; i <= n; i++)
//         {
//             for(int j = 0; j <= m; j++)
//             {
//                 cout << dp[i][j] << " ";
//             }
//             cout << endl;
//         }
        
        int x = n;
        int y = m;
        string lcs = "";
        string sup = "";
        while(x >= 1 && y >= 1)
        {
            if(dp[x][y] != dp[x-1][y] && dp[x][y] != dp[x][y-1])
            {
                lcs += str1[x-1];
                x--;
                y--;   
            }
            else if(dp[x][y] == dp[x-1][y])
            {
                x--;
            }
            else if(dp[x][y] == dp[x][y-1])
            {
                y--;
            }
        }
        reverse(lcs.begin(),lcs.end());
        
        int a=0, b =0;
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