class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        string ans = "";
        while(i < n)
        {
            string res = "";
            while(i < n && s[i] != ' ')
            {
                res += s[i++];
            }
            reverse(res.begin(), res.end());
            ans += res;
            if(i < n)
                ans += s[i];
            i++;
        }
        return ans;
    }
};