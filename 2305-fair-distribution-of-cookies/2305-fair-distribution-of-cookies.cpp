class Solution {
public:
    int ans;
    
    void helper(vector <int> &c, vector <int> &res, int i,int k)
    {
        if(i == c.size())
        {
            int cnt = 0;
            
            for(int j = 0; j < k; j++)
            {
                cnt = max(cnt, res[j]);
            }
            
            ans = min(ans, cnt);
            return;
        }
        
        for(int j = 0; j < k; j++)
        {
            res[j] += c[i];
            helper(c,res,i+1,k);
            res[j] -= c[i];
        }
    }
    
    int distributeCookies(vector<int>& c, int k) {
        ans = INT_MAX;
        int n = c.size();
        vector <int> res(k,0);
        helper(c,res,0,k);
        return ans;
    }
};