// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	int helper(int coins[], int M, int V, int i,int **dp)
	{
	    
	    if(V == 0)
	    return 0;
	    
	    
	    if(i == M || V < 0)
	    {
	        return 1e9;
	    }
	    
	    if(dp[i][V] != -1)
	    return dp[i][V];
	    
	    // can take this coin
	    
	    int ans1 = 1e9, ans2 = 1e9;
	    
	    ans1 = 1 + helper(coins, M, V - coins[i], i, dp);
	    
	    ans2 = helper(coins, M, V, i+1, dp);
	    
	    return dp[i][V] =  min(ans1, ans2);
	    
	}
	
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int ** dp = new int*[M+1];
	    
	    for(int i = 0 ; i<=M; i++)
	    {
	        dp[i] = new int[V+1];
	        for(int j = 0; j <=V; j++)
	        dp[i][j] = -1;
	    }
	    int ans = helper(coins, M, V, 0,dp);
	    
	    if(ans == 1e9)
	    ans = -1;
	    
	    return ans;
	    
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends