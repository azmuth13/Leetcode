// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    
    int helper(int price[], int n, int i, int len,int**dp)
    {
        if(len == 0)
        return 0;
        
        if(i >= n || len < 0)
        return -1e9;
        
        if(dp[i][len] != -1)
        return dp[i][len];
        
        int ans1 = 0, ans2 = 0;
        // option 1
        
    
        ans1 = price[i] + helper(price, n, i, len - i-1,dp);
        
        // option 2
        
        ans2 = helper(price, n, i+1, len,dp);
        
        return dp[i][len] = max(ans1, ans2);
        
    }
  
    int cutRod(int price[], int n) {
        //code here
        int ** dp = new int*[n+1];
        for(int i = 0; i <= n; i++)
        {
            dp[i] = new int[n+1];
            for(int j = 0; j <= n; j++)
            dp[i][j] = -1;
        }
        int ans = helper(price, n, 0, n,dp);
        return ans;
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