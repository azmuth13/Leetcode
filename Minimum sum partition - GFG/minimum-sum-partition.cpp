// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
  int res;
  int helper(int nums[], int i, int curr, int sum, int n, int ** dp)
    {
        if(i >= n)
        {
            res = min(res, abs(curr - (sum-curr)));
            return abs(curr - (sum-curr));
        }
        
        if(dp[i][curr] != -1)
        return dp[i][curr];
        
        int ans1 = helper(nums, i+1, curr + nums[i], sum,n, dp);
        
        int ans2 = helper(nums, i+1, curr, sum,n, dp);
            
        return dp[i][curr] = min(ans1, ans2);
        
    }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
        res = 1e9;
        
        
        
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        
        int ** dp = new int*[n+1];
        
        for(int i = 0; i <= n; i++)
        {
            dp[i] = new int[sum+1];
            for(int j = 0; j <= sum; j++)
            {
                dp[i][j] = -1;
            }
        }
        
        int ans = helper(arr, 0, 0, sum,n, dp);
        return res;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends