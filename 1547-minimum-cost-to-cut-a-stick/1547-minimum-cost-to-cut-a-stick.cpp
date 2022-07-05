class Solution {
public:
    int n;
    int memo[103][103];
    int helper(vector <int>& cuts, int l, int r)
    {
        if(r-l <= 1)
            return 0;
        
        if(memo[l][r] != -1) return memo[l][r];
        
        int ans = 1e9;
        int cost = 0;
        
//         if(l==0)
//         {
//             cost += cuts[l];
//         }
//         else
//         {
//             cost += cuts[l] - cuts[l-1];
//         }
        
//         if(r == cuts.size()-1)
//         {
//             cost += n - cuts[r];
//         }
//         else
//         {
//             cost += cuts[r+1] - cuts[r];
//         }
        
        cost += cuts[r] - cuts[l];
        
        for(int i = l+1; i < r; i++)
        {
            ans = min(ans, cost + helper(cuts,l,i) + helper(cuts,i,r));
        }
        
        return memo[l][r] = ans;
    }
    int minCost(int _n, vector<int>& cuts) {
        n = _n;
        
        memset(memo,-1,sizeof memo);
        cuts.push_back(0);
        cuts.push_back(n);
        int sz = cuts.size();
        sort(cuts.begin(), cuts.end());
        
        int ans = helper(cuts,0,sz-1);
        return ans;
    }
};