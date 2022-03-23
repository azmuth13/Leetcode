// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    int helper(string &a, string &b, int i, int j, vector < vector <int> > &dp)
    {
        
        if(i >= a.size() || j >= b.size())
        return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        if(a[i] == b[j])
        {
            return dp[i][j] = 1 + helper(a,b, i+1, j+1, dp);
        }
        else
        {
            return 0;
        }
        
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        
        vector < vector <int> > dp(n+1, vector <int> (m+1, -1));
        
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans = max(ans, helper(S1, S2, i, j, dp));
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends