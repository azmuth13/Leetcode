class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26] = {};
        for(auto m : magazine)
            a[m-'a']++;
        
        for(auto r : ransomNote)
            a[r-'a']--;
        
        for(int i = 0; i < 26; i++)
            if(a[i] < 0)
                return false;
        return true;
    }
};