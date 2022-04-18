class Solution {
public:
    int res;
    int memo[75][5000];
    int helper(vector<vector<int>>& mat, int i, int sum, int target)
    {
        if(i == mat.size())
        {
            //res = min(res, abs(target - sum));
            return abs(target - sum);
        }
        
        if(memo[i][sum] != -1)
            return memo[i][sum];
        
        int ans = 1e9;
        
        for(int j = 0; j < mat[0].size(); j++)
        {
            ans = min(ans, helper(mat, i+1, sum + mat[i][j], target));
        }
        
        return memo[i][sum] = ans;
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
        memset(memo, -1, sizeof memo);
        int ans = helper(mat, 0, 0, target);
        res = 1e9;
        
        return ans;
        
    }
};