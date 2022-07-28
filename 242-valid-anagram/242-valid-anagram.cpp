class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26] = {};
        for(auto &x : s)
        {
            a[x-'a']++;
        }
        
        for(auto &x : t)
        {
            a[x-'a']--;
        }
        
        for(int i = 0; i < 26; i++)
            if(a[i]!=0)return false;
        return true;
    }
};