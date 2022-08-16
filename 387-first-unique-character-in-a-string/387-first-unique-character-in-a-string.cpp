class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        int ans = -1;
        int a[26] = {};
        for(int i = 0; i < n; i++)
            a[s[i]-'a']++;
        for(int i = 0; i < n; i++)
        if(a[s[i]-'a'] == 1)
            return i;
        return ans;
    }
};