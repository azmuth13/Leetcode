// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	
	int mod = 1e9 + 7;
	
	int helper(int arr[], int i, int n, int sum, int**dp)
    {
        if(sum < 0) return 0;
        
        if(i == n)
        {
            if(sum == 0)
            return 1;
            
            return 0;
        }
        
        if(dp[i][sum] != -1)
        return dp[i][sum];
        
        int ans1 = helper(arr, i+1, n, sum-arr[i],dp);
        
        int ans2 = helper(arr, i+1, n, sum,dp);
        
        return dp[i][sum] = (ans1+ans2)%mod;
    }
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        int ** dp = new int*[n+1];
        for(int i = 0; i <= n; i++)
        {
            dp[i] = new int[sum+1];
            
            for(int j = 0; j <= sum; j++)
            dp[i][j] = -1;
        }
        
        int ans = helper(arr, 0, n, sum, dp);
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
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends