class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        unordered_map <char, vector <int> > mp;
        for(char ch = 'A'; ch <= 'Z'; ch++)
        {
            mp[ch].push_back(-1e9);
        }
        for(int i = 0; i < n; i++)
        {
            mp[s[i]].push_back(i);
        }
        for(char ch = 'A'; ch <= 'Z'; ch++)
        {
            mp[ch].push_back(1e9);
        }
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            auto it = lower_bound(mp[s[i]].begin(), mp[s[i]].end(), i+1);
            int right, left;
            
            if(*it == 1e9)
                right = n;
            else
                right = *it;
            
            it = lower_bound(mp[s[i]].begin(), mp[s[i]].end(), i);
            
            it--;
            
            if(*it == -1e9)
                left = -1;
            else
                left = *it;
            
            int lenL = i-left;
            int lenR = right-i;
            ans += lenL*lenR;
        }
        return ans;
    }
};