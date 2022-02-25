class Solution {
public:
    
    int squareSum(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            int val = n%10;
            sum += (val*val);
            n/=10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        
        unordered_map <int, int> mp;
        
        while(1)
        {
            if(n==1)
                return true;
            
            if(mp.find(n) != mp.end())
                return false;
            
            mp[n]++;
            
            n = squareSum(n);
        }
        return false;
    }
};