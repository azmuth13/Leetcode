class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n == 0 || n == 1)
            return n;
        
        if(n < 0)
            return false;
        long long res = 1;
        while(res < INT_MAX)
            res = res * 3;
        return (res%n == 0);
    }
};