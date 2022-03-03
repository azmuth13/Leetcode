class Solution {
public:
    bool canMeasureWater(int j1, int j2, int t) {
        if(j1 + j2 < t)
            return false;
        int d = __gcd(j1,j2);
        return (t%d==0);
    }
};