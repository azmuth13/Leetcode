class Solution {
public:
    int gcd(int p, int q)
    {
        if(p==0)
            return q;
        
        return gcd(q%p,p);
    }
    int mirrorReflection(int p, int q) {
        int lcm = p*q/(gcd(p,q));
        p = lcm/p;
        q = lcm/q;
        
        if((p&1) && (q&1))
            return 1;
                
        if(p%2==0 && (q&1))
            return 0;
        
        
        return 2;
    }
};