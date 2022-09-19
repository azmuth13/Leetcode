class Solution {
public:
    long long mod = 1e9 + 7;
    unordered_map <int, vector <int> > hatPeople;
    int N;
    long long memo[41][(1<<10)+ 1];
    long long helper(int hatId, int mask)
    {
        
        
        if(mask == ((1<<N)-1))
            return 1;
        
        if(hatId == 41)
            return 0;
        
        if(memo[hatId][mask] != -1)
            return memo[hatId][mask];
        
        if(hatPeople.find(hatId) == hatPeople.end())
        {
            return helper(hatId+1,mask);
        }
        
        long long count = 0;
        count += helper(hatId+1,mask);
        count%=mod;
        for(int i = 0; i < hatPeople[hatId].size(); i++)
        {
            int peep = hatPeople[hatId][i];
            if(mask&(1<<peep)) continue;
            
            count += helper(hatId+1,mask|(1<<peep))%mod;
            count%=mod;
        }
        
        return memo[hatId][mask] = count;
    }
    
    int numberWays(vector<vector<int>>& hats) {
        // people -> 10,
        N = hats.size();
        for(int i = 0; i < hats.size(); i++)
        {
            for(int j = 0; j < hats[i].size(); j++)
            {
                hatPeople[hats[i][j]].push_back(i);
            }
        }
        memset(memo,-1,sizeof memo);
        long long ans = helper(1,0);
        ans%=mod;
        return ans;
    }
};