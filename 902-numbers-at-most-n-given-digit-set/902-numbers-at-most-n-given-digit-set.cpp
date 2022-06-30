class Solution {
public:
    int memo[10][2][2];
    int maxi;
    int helper(vector <int> &digits, string &s, int i, int f, int c)
    {
        
        if(i >= s.size())
        {
            if(c)
                return 1;
            
            return 0;
        }
        
        if(memo[i][f][c] != -1) return memo[i][f][c];
        
        int ans = 0;
        
        int up = s[i] - '0';
        
        if(f)
        {
            up = maxi;
        }
        
        if(!c)
        {
            ans += helper(digits,s,i+1,1,c);
        
            for(int j = 0; j < digits.size(); j++)
            {
                if(digits[j] > up) break;
                ans += helper(digits,s,i+1,f||(digits[j]<up),1);
            }
        }
        else
        {
            for(int j = 0; j < digits.size(); j++)
            {
                if(digits[j] > up) break;
                ans += helper(digits,s,i+1,f||(digits[j]<up),1);
            }
        }
 
        return memo[i][f][c] = ans;
    }
    
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        
        string s = to_string(n);
        vector <int> digs;
        for(int i = 0; i < digits.size(); i++)
        {
            digs.push_back(stoi(digits[i]));
        }
        
        maxi = *max_element(digs.begin(),digs.end());
        
        int ans = 0;
        memset(memo,-1,sizeof memo);
        ans = helper(digs,s,0,0,0);
        return ans;
    }
};