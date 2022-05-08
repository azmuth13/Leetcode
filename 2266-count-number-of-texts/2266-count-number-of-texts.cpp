class Solution {
public:
    
    map <string, char> mp;
    int mod = (int)1e9 + 7;
    
    int dp[100005];
    int helper(string &p, int i)
    {
        if(i == (int)p.size())
            return 1;
        
        if(dp[i] != -1)
            return dp[i];
        
        string curr = "";
        int ans = 0;
        
        for(int j = i; j < p.size(); j++)
        {
            curr += p[j];
            if(mp.find(curr) != mp.end())
            {
                ans += helper(p, j+1);
                ans %= mod;
            }
            
            if((int)curr.size() == 4)
                break;
        }
        
        return dp[i] = ans%mod;
    }
    
    int countTexts(string p) {
        
        mp["2"] = 'a';
        mp["22"] = 'b';
        mp["222"] = 'c';
        
        mp["3"] = 'd';
        mp["33"] = 'e';
        mp["333"] = 'f';
        
        mp["4"] = 'g';
        mp["44"] = 'h';
        mp["444"] = 'i';
        
        mp["5"] = 'j';
        mp["55"] = 'k';
        mp["555"] = 'l';
        
        mp["6"] = 'm';
        mp["66"] = 'n';
        mp["666"] = 'o';
        
        mp["7"] = 'p';
        mp["77"] = 'q';
        mp["777"] = 'r';
        mp["7777"] = 's';
        
        mp["8"] = 't';
        mp["88"] = 'u';
        mp["888"] = 'v';
        
        mp["9"] = 'w';
        mp["99"] = 'x';
        mp["999"] = 'y';
        mp["9999"] = 'z';
        memset(dp, -1, sizeof dp);
        int ans = helper(p, 0);
        return ans%mod;
    }
};