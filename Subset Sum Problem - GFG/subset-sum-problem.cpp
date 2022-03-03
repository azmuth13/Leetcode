// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    
    bool helper(int arr[], int i, int n, int sum, int ** dp)
    {
        if(sum == 0)
        return true;
        
        if(i == n)
        return false;
        
        if(dp[i][sum] != -1)
        return dp[i][sum];

        return dp[i][sum] = (helper(arr, i+1, n, sum-arr[i], dp)|helper(arr, i+1, n, sum, dp));
    }

    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        
        int ** dp = new int*[N+1];
        
        for(int i = 0; i <= N; i++)
        {
            dp[i] = new int[sum+1];
            for(int j = 0; j <= sum; j++)
            dp[i][j] = -1;
        }
        
        bool ans = helper(arr, 0, N, sum, dp);
        
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends