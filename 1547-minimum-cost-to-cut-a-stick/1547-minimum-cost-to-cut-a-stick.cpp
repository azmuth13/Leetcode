class Solution {
public:
    int n;
    int memo[101][101];
    int helper(vector <int>& cuts, int l, int r)
    {
        if(l > r)
            return 0;
        
        if(memo[l][r] != -1) return memo[l][r];
        
        int ans = 1e9;
        int cost = 0;
        
        if(l==0)
        {
            cost += cuts[l];
        }
        else
        {
            cost += cuts[l] - cuts[l-1];
        }
        
        if(r == cuts.size()-1)
        {
            cost += n - cuts[r];
        }
        else
        {
            cost += cuts[r+1] - cuts[r];
        }
        
        cost += cuts[r] - cuts[l];
        
        for(int i = l; i <= r; i++)
        {
            ans = min(ans, cost + helper(cuts,l,i-1) + helper(cuts,i+1,r));
        }
        
        return memo[l][r] = ans;
    }
    int minCost(int _n, vector<int>& cuts) {
        n = _n;
        int sz = cuts.size();
        memset(memo,-1,sizeof memo);
        sort(cuts.begin(), cuts.end());
        
        int ans = helper(cuts,0,sz-1);
        return ans;
    }
};