class Solution {
public:
    
    int find(vector<vector<int>>& events, int i)
    {
//         j > i
//         events[j][0] > events[i][1]
        int n = events.size();
        int l = i+1, r = n-1;
        int ans = n;
        while(l <= r)
        {
            int j = (l + r)/2;
            if(events[j][0] > events[i][1])
            {
                ans = j;
                r = j - 1;
            }
            else
            {
                l = j + 1;
            }
        }
        return ans;
    }
    
    
    int helper(vector<vector<int>>& events, int k, int i, int ** memo)
    {
        // base cases start
        
        if(i >= events.size()) return 0;
        if(k == 0) return 0;
        
        if(memo[i][k] != -1)
            return memo[i][k];
        // base cases end
        
        
        
        // select this event
        int next = find(events, i);
        int ans1 = events[i][2] + helper(events, k-1, next, memo);
        
        // do not select
        int ans2 = helper(events, k, i+1, memo);
        return memo[i][k] = max(ans1, ans2);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        int n = events.size();
        int ** memo = new int*[n+1];
        for(int i = 0; i <= n; i++)
        {
            memo[i] = new int[k+1];
            for(int j = 0; j <= k; j++)
                memo[i][j] = -1;
        }
        sort(events.begin(), events.end());
        
        int ans = helper(events, k, 0, memo);
//         for(int i = 0; i <= n; i++)
//             delete (memo[i]);
        
//         delete (memo);
        
        return ans;
        
    }
};