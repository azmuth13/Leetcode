class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        if(n != m)
            return false;
        
        int a[26] = {};
        int b[26] = {};
        
        for(int i = 0; i < n; i++)
        {
            a[word1[i]-'a']++;
        }
        
        for(int i = 0; i < n; i++)
        {
            b[word2[i]-'a']++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(a[i] == 0 && b[i] > 0)
                return false;
            
            if(a[i] > 0 && b[i] == 0)
                return false;
        }
        multiset <int> st1, st2;
        for(int i = 0; i < 26; i++)
        {
            st1.insert(a[i]);
            st2.insert(b[i]);
        }
        return st1==st2;
    }
};