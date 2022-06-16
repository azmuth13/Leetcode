class Solution {
public:
    unordered_map <string, int> mp;
    
    int helper(string &s, int i, vector <int> &dp)
    {
        
        if(i >= s.size()){
            //cout << "YES\n";
            return 1;
        }
           
        //cout << s << endl;
        int ans = false;
        
//         if(dp[i] != -1)
//             return dp[i];
        
        int sz = s.size();
        for(int j = i; j < sz; j++)
        {
            string res = "";
            
            for(int k = i; k <= j; k++)
                res += s[k];
            // cout << res << endl;
            if(mp.find(res) != mp.end())
            {
                ans |= helper(s,j+1,dp);
                if(ans) return ans;
            }
        }
        return dp[i] = ans;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        int n = words.size();
        for(int i = 0; i < n; i++)
        {
            mp[words[i]]++;
        }
        
        vector <string> ans;
        vector <int> dp(31,-1);
        for(int i = 0; i < n; i++)
        {
            mp.erase(words[i]);
            if(helper(words[i],0,dp))
            {
                
                ans.push_back(words[i]);
            }
            dp.resize(31,-1);
            mp[words[i]]++;
            //cout << endl;
        }
        
        return ans;
    }
};