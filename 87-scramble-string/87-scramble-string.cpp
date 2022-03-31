class Solution {
public:
    
    map < pair <string , string>, int> mp;
    
    bool isScramble(string s1, string s2) {
        
        if(s1.size() != s2.size())
            return false;
        
        if(s1 == s2)
            return true;
        
        string c1 = s1;
        string c2 = s2;
        int n = s1.size();
        
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        
        if(c1 != c2)
            return false;
        
        if(mp.find({s1, s2}) != mp.end())
            return mp[{s1, s2}];
        
        bool ans = false;
        
        for(int i = 1; i < n; i++)
        {
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) 
               && isScramble(s1.substr(i,-1), s2.substr(i,-1)))
               ans |= true;
            
            if(isScramble(s1.substr(0,i), s2.substr(n-i,i)) 
               && isScramble(s1.substr(i,n-i), s2.substr(0,n-i)))
               ans |= true;
        }
        
        return mp[{s1, s2}] = ans;
    }
};