class Solution {
public:
    
    int helper(int n, int k)
    {
        if(n==1)
            return 0;
        int ans = helper(n-1,k);
        
        return (ans+k)%n;
        
    }
    
    int findTheWinner(int n, int k) {
        int ans = helper(n,k);
        return ans+1;
    }
};