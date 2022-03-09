// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    
    int helper(int price[], int len,int*dp)
    {
        if(len == 0)
        return 0;
        
        if(dp[len] != -1)
        return dp[len];
        
        int ans = 0;
        for(int i = 1; i <= len; i++)
        {
            ans = max(ans, price[i-1] + helper(price,len - i,dp));
        }
        
        return dp[len] = ans;
    }
  
    int cutRod(int price[], int n) {
        //code here
        int ** dp = new int*[n+1];
        int * dp3 = new int[n+1];
        
        for(int i = 0; i <= n; i++)
        {
            dp3[i] = -1;
            dp[i] = new int[n+1];
            for(int j = 0; j <= n; j++)
            dp[i][j] = 0;
        }
        int ans = helper(price, n,dp3);
        return ans;
        
        for(int i = 0; i <= n; i++)
        {
            dp[i][n] = 0;
        }
        
        
        int dp2[n+1] = {};
        
        // length
        for(int i = 1; i <= n; i++)
        {
            // indexes
            for(int j = 1; j <= i; j++)
            {
                // if(j >= i)
                // {
                //     dp[i][j] = max(dp[i-1][j], price[i-1] + dp[i][j - i]);
                // }
                // else
                // {
                //     dp[i][j] = dp[i-1][j];
                // }
                
                dp2[i] = max(dp2[i], price[j-1] + dp2[i - j]);
                
            }
        }
        
        //return dp[n][n];
        return dp2[n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends