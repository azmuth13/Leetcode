class Solution {
public:
    
    int helper(string &tar, vector <vector <int> >& count, map <string,int>&dp)
    {
        if((int)tar.size() == 0)
            return 0;
        
        int ans = 1e9;
        
        if(dp.find({tar}) != dp.end())
            return dp[tar];
        
        for(int i = 0; i < count.size(); i++)
        {
            vector <int> freq = count[i];
            string rem = "";
            for(int j = 0; j < tar.size(); j++)
            {
                if(freq[tar[j]-'a']) freq[tar[j]-'a']--;
                else rem += tar[j];
            }
            if(rem != tar)
            ans = min(ans, 1 + helper(rem,count,dp));
        }
        
        return dp[tar] = ans;
    }
    
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector < vector <int> > count(n,vector <int> (26,0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < stickers[i].size(); j++)
            {
                count[i][stickers[i][j] - 'a']++;
            }
        }
        map <string, int> dp;
        int ans = helper(target,count,dp);
        if(ans == 1e9) ans = -1;
        return ans;
        
    }
};