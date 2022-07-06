class Solution {
public:
    int memo[32][32][32];
    int helper(vector <int> &stones, int l, int r, int piles, int k)
    {
        if(l==r && piles==1) return 0;
        
        
        if(l==r) return 1e9;
        
        if(memo[l][r][piles] != -1) return memo[l][r][piles];
        
        int ans = 1e9;
        if(piles == 1)
        {
            ans = helper(stones,l,r,k,k) + ((l==0)?stones[r]:(stones[r] - stones[l-1]));
        }
        else
        {
            for(int t = l; t < r; t++)
            {
                ans = min(ans, helper(stones,l,t,1,k) + helper(stones,t+1,r,piles-1,k));
            }
        }
        
        return memo[l][r][piles] = ans;
    } 
    
    int mergeStones(vector<int>& stones, int k) {
        
        int n = stones.size();
        
        for(int i = 1; i < n; i++)
        {
            stones[i] += stones[i-1];
        }
        
        if((n-1)%(k-1) != 0) return -1;
        memset(memo,-1,sizeof memo);
        int ans = helper(stones,0,n-1,1,k);
        return ans;
    }
};