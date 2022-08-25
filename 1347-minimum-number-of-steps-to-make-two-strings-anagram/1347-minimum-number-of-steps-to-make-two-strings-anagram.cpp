class Solution {
public:
    int minSteps(string s, string t) {
        int a[26] = {};
        int b[26] = {};
        
        for(auto &m : s)
            a[m-'a']++;
        
        for(auto &r : t)
            b[r-'a']++;
        
        int ans = 0;
        for(int i = 0; i < 26; i++)
        {
            ans += abs(a[i]-b[i]);
        }
        return ans/2;
    }
};