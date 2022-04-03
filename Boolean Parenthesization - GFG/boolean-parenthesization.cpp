// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int memo[201][201][3];
    int helper(int i, int j, string &s, bool isTrue)
    {
        // base case
        if(i == j)
        {
            if(isTrue)
            {
                if(s[i] == 'T')
                    return 1;
                else
                    return 0;
            }
            else
            {
                if(s[i] == 'F')
                    return 1;
                else
                    return 0;
            }
        }
        
        if(i > j)
            return 0;
        
        if(memo[i][j][isTrue] != -1)
            return memo[i][j][isTrue];
        int mod = 1003;
        
        int ans = 0;
        
        for(int k = i; k < j; k+=2)
        {
            int lf = 0, rf = 0, lt = 0, rt = 0;
            
            lf = helper(i, k, s, 0);
            lt = helper(i, k, s, 1);
            
            rf = helper(k+2, j, s, 0);
            rt = helper(k+2, j, s, 1);
            
            if(s[k+1] == '&')
            {
                if(isTrue)
                {
                    ans += lt*rt;
                    ans %= mod;
                }
                else
                {
                    ans += lf*rf;
                    ans %= mod;
                    ans += lf*rt;
                    ans %= mod;
                    ans += lt*rf;
                    ans %= mod;
                }
            }
            
            if(s[k+1] == '|')
            {
                if(isTrue)
                {
                    ans += lt*rf;
                    ans %= mod;
                    ans += lt*rt;
                    ans %= mod;
                    ans += lf*rt;
                    ans %= mod;
                }
                else
                {
                   ans += lf*rf;
                   ans %= mod;
                }
            }
            
            if(s[k+1] == '^')
            {
                if(isTrue)
                {
                    ans += lt*rf;
                    ans %= mod;
                    ans += lf*rt;
                    ans %= mod;
                }
                else
                {
                   ans += lf*rf;
                   ans %= mod;
                   ans += lt*rt;
                   ans %= mod;
                }
            }
        }
        
        return memo[i][j][isTrue] = ans;
    }

    int countWays(int N, string S){
        // code here
        memset(memo, -1, sizeof memo);
        int ans = helper(0, N-1, S, 1);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends