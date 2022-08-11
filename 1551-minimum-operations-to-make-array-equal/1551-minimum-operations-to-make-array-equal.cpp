class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        if(n&1)
        {
            for(int i = 0; i < n/2; i++)
            {
                ans += n - (2*i + 1); 
            }
        }
        else
        {
            for(int i = 0; i < n/2; i++)
            {
                ans += n - (2*i+1);
            }
        }
        return ans;
    }
};
// n=6
// 1 3 5 7 9 11
// 6 3 5 7 9 6 - 5
// 6 6 5 7 6 6 - 3
// 6 6 6 6 6 6 - 1
    
// 1 3 5 7 9
//     n = 5, ans = 2 + 4 = 6