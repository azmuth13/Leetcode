class Solution {
public:
    
    /*
    [1,6,2,14,5,17,4]
16
9
7
    */
    
    map <int, int> mp;
    int memo[10005][3];
    int helper(int curr, int a, int b, int x, int count)
    {
        if(curr == x)
            return 0;
    
        if(curr > 10000 || curr < 0)
            return 1e9;
         
        if(memo[curr][count] != -1)
            return memo[curr][count];
        
        int ans1 = 1e9, ans2 = 1e9;
        
        memo[curr][count] = 1e9;
        
        if(mp.find(curr + a) == mp.end())
        {
            ans1 = 1 + helper(curr+a,a, b, x, 1);
        }
        
        if(count > 0 && curr - b >= 0 && mp.find(curr - b) == mp.end())
        {
            ans2 = 1 + helper(curr - b, a, b, x, count - 1);
        }
        
        return memo[curr][count] = min(memo[curr][count],min(ans1, ans2)) ;
    }
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        
        for(auto &x : forbidden)
            mp[x]++;
        
        memset(memo, -1, sizeof memo);
        
        int ans = helper(0, a, b, x, 1);
        
        if(ans == 1e9)
            ans = -1;
        
        return ans;
    }
};