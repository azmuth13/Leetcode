class Solution {
public:
    
    int mod = 1e9 + 7;
    
    long long fact(long long n)
    {
        if(n==0)
            return 1;
            
        return (n * fact(n-1))%mod;
    }
    
    int countOrders(int n) {
        
        // n pickups and n deliveries
        
        long long ans = fact(n);
        
        long long val = 2*n-1;
        
        for(int i = 1; i <= val; i+=2)
        {
            ans = (ans%mod * i%mod)%mod;
        }
        
        return ans;
    }
};